// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleAbility.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GrappleTargetComponent.h"

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
	UE_LOG(LogTemp, Warning, TEXT("Can't Grapple"));
}

void UGrappleAbility::GatherTargets()
{
	float GrappleRange = 100.f;
	AActor* OwningCharacter = GetOwner();
	if (OwningCharacter) {
	//	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), OwningCharacter->GetActorLocation(),GrappleRange,);
	}
	//Create Overlap Sphere to capture all objects that have a grapple target component

	//Find the target that is the closest to the player's forward facing vector
	FindBestTarget();
}

void UGrappleAbility::FindBestTarget()
{
}

