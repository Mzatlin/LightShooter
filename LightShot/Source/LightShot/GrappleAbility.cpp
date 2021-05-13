// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleAbility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GrappleTargetComponent.h"
#include "BreakableObject.h"
#include "Math/Vector.h"
#include "GrappleHook.h"

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
	case Firing:
		break;
	case Attatched:
		break;
	case Released:
		break;
	 }
	// ...
}

void UGrappleAbility::TryGrapple()
{
	if (CurrentGrappleState == Retracted && GrappleTarget) 
	{
		if (ProjectileClass) {

			FRotator SpawnRotation = FRotator(0,0,0);
			AGrappleHook* TempProjectile = GetWorld()->SpawnActor<AGrappleHook>(ProjectileClass, OwningCharacter->GetActorLocation(), SpawnRotation);
			TempProjectile->SetDirectionToTarget(GrappleTarget);
			TempProjectile->SetOwner(GetOwner());
			//CurrentGrappleState = Firing;
		}
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
	UClass* seekClass = ABreakableObject::StaticClass();//TSubclassOf<UGrappleTargetComponent>(); // NULL;
	TArray<TEnumAsByte<EObjectTypeQuery>> traceObjectTypes;
	traceObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_GameTraceChannel2));

	if (OwningCharacter) 
	{
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
	//Create Overlap Sphere to capture all objects that have a grapple target component

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
	for (AActor* overlap : outActors) 
	{
		UGrappleTargetComponent* target = overlap->FindComponentByClass<UGrappleTargetComponent>();
		if (!target)
		{
			continue;
		}

		FVector currentDirection = (overlap->GetActorLocation() - OwningCharacter->GetActorLocation()).GetSafeNormal(0.001);
		float currentAngle = FMath::Acos(FVector::DotProduct(currentDirection, OwningCharacter->GetActorForwardVector()));

		if (!BestTarget || currentAngle < bestAngle) {
			BestTarget = target;
			bestAngle = currentAngle;
		}
	}

	return BestTarget;
}

