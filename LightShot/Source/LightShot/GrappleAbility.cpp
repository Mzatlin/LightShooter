// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleAbility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GrappleTargetComponent.h"
#include "BreakableObject.h"
#include "Math/Vector.h"
#include "CableActor.h"
#include "CableComponent.h"
#include "Engine/EngineTypes.h"
#include "GrappleHook.h"
#include "IGrappledResponse.h"
#include "GameFramework/Actor.h"




// Sets default values for this component's properties
UGrappleAbility::UGrappleAbility()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrappleAbility::BeginPlay()
{
	Super::BeginPlay();
	OwningCharacter = GetOwner();
	// ...
	
}


// Called every frame
void UGrappleAbility::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	switch (CurrentGrappleState) {
	case Retracted:
		GatherTargets();
		break;
	case HeadingToTarget:
		MoveToTarget();
		break;
	case Released:
		CleanUpHook();
		HandleGrappledTarget();
		break;
	 }
	// ...
}

void UGrappleAbility::AttatchHookToTarget()
{
	if (ProjectileClass && CableClass) {

		FRotator SpawnRotation = FRotator(0, 0, 0);
		HookProjectile = GetWorld()->SpawnActor<AGrappleHook>(ProjectileClass, OwningCharacter->GetActorLocation(), SpawnRotation);
		HookProjectile->SetDirectionToTarget(GrappleTarget);
		HookProjectile->SetOwner(OwningCharacter);
		Cable = GetWorld()->SpawnActor<ACableActor>(CableClass, OwningCharacter->GetActorLocation(), SpawnRotation);
		TArray<UStaticMeshComponent>components;
		Cable->CableComponent->AttachToComponent(OwningCharacter->GetRootComponent(),
			FAttachmentTransformRules(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				true));
		//send cable component to latchon
		Cable->CableComponent->SetAttachEndTo(HookProjectile, "None");

		

		FRotator playerRotation = ((GrappleTarget->GetOwner()->GetActorLocation() - OwningCharacter->GetActorLocation()).GetSafeNormal(0.001)).Rotation();
		UStaticMeshComponent* TargetMesh = OwningCharacter->FindComponentByClass<UStaticMeshComponent>();
		if (TargetMesh) {
			TargetMesh->SetWorldRotation(playerRotation);
		}
		//Note, this will cause the ship to rotate around the grappled axis, which is cool, but not needed.
		//OwningCharacter->SetActorRotation((GrappleTarget->GetOwner()->GetActorLocation() - OwningCharacter->GetActorLocation()).Rotation());
		CurrentGrappleState = Attatched;
	}
}

void UGrappleAbility::CleanUpHook()
{
	if (HookProjectile  && Cable && (!HookProjectile->GetAttachState() || FVector::DistSquared(OwningCharacter->GetActorLocation(), HookProjectile->GetActorLocation()) <= 14500))
	{
		HookProjectile->DetatchHook();
		Cable->Destroy();
		HookProjectile->Destroy();
		CurrentGrappleState = Retracted;
	}
}

void UGrappleAbility::HandleGrappledTarget()
{
	AActor* TargetActor = GrappleTarget->GetOwner();//currently redundant
}

void UGrappleAbility::MoveToTarget()
{
	AActor* TargetActor = GrappleTarget->GetOwner();
	if (TargetActor && FVector::Distance(GetOwner()->GetActorLocation(), TargetActor->GetActorLocation()) > 100)
	{
		OwningCharacter->AddActorLocalOffset((TargetActor->GetActorLocation() - OwningCharacter->GetActorLocation()).GetSafeNormal(0.001) * 20);
		return;
	}
	if(TargetActor && TargetActor->GetClass()->ImplementsInterface(UIGrappledResponse::StaticClass()))
	{
		HookProjectile->SetAttachState(false);
		HookProjectile->DetatchHook();
		CurrentGrappleState = Released;
		IIGrappledResponse::Execute_RespondToGrapple(TargetActor);
	}
}

void UGrappleAbility::TryGrapple()
{
	if (CurrentGrappleState == Retracted && GrappleTarget) 
	{
		AttatchHookToTarget();
	}
	else if (CurrentGrappleState == Attatched && HookProjectile) 
	{
		HookProjectile->ReturnDirectionToSender();
		CurrentGrappleState = Released;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Can't Grapple"));
	}
}

void UGrappleAbility::GatherTargets()
{
	TArray<AActor*> outActors;
	TArray<AActor*> ignoreActors;
	ignoreActors.Add(OwningCharacter);
	UClass* seekClass = ABreakableObject::StaticClass();
	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel2));

	if (OwningCharacter) 
	{
		//Create Overlap Sphere to capture all objects that have a grapple target component
		UKismetSystemLibrary::SphereOverlapActors(
			GetWorld(),
			OwningCharacter->GetActorLocation(),
			GrappleRange,
			traceObjectTypes,
			seekClass,
			ignoreActors,
			outActors
			);
	}
	//UKismetSystemLibrary::DrawDebugSphere(GetWorld(), OwningCharacter->GetActorLocation(), GrappleRange, 12, FColor::Red, true, 10.0f);
	

	//Find the target that is the closest to the player's forward facing vector
	GrappleTarget = FindBestTarget(outActors);
	
	if (GrappleTarget) 
	{
		GrappleTarget->SetTargetActive();
	}
}

UGrappleTargetComponent* UGrappleAbility::FindBestTarget(TArray<AActor*> &outActors)
{
	float bestAngle = INT_MAX;
	BestTarget = nullptr;

	for (AActor* overlap : outActors) 
	{

		//Filter out any Actor that doesn't have a UGrappleTargetComponnet 
		UGrappleTargetComponent* target = overlap->FindComponentByClass<UGrappleTargetComponent>();
		if (!target)
		{
			continue;
		}

		//Get the current angle of the vector pointing from the target to the player
		CurrentDirection = (overlap->GetActorLocation() - OwningCharacter->GetActorLocation()).GetSafeNormal(0.001);
		float currentAngle = FMath::Acos(FVector::DotProduct(CurrentDirection, OwningCharacter->GetActorForwardVector()));

		//If the current angle is smaller than the best angle, set that as the next best angle
		if (!BestTarget || currentAngle < bestAngle)
		{
			BestTarget = target;
			bestAngle = currentAngle;
		}

	}

	return BestTarget;
}



