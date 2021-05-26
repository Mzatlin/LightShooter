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
	case Attatched:
		break;
	case Released:
		CleanUpHook();
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

		//Note, this will cause the ship to rotate around the grappled axis, which is cool, but not needed.
		//	OwningCharacter->SetRelativeRotation((GrappleTarget->GetOwner()->GetActorLocation() - OwningCharacter->GetActorLocation()).Rotation());
		CurrentGrappleState = Attatched;
	}
}

void UGrappleAbility::CleanUpHook()
{
	if (HookProjectile && HookProjectile->GetAttachState() && Cable) 
	{
		Cable->Destroy();
		HookProjectile->Destroy();
		CurrentGrappleState = Retracted;
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
	float GrappleRange = 800.f;
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
		UGrappleTargetComponent* target = overlap->FindComponentByClass<UGrappleTargetComponent>();
		if (!target)
		{
			continue;
		}

		CurrentDirection = (overlap->GetActorLocation() - OwningCharacter->GetActorLocation()).GetSafeNormal(0.001);
		float currentAngle = FMath::Acos(FVector::DotProduct(CurrentDirection, OwningCharacter->GetActorForwardVector()));

		if (!BestTarget || currentAngle < bestAngle) {
			BestTarget = target;
			bestAngle = currentAngle;
		}
	}

	return BestTarget;
}



