// Fill out your copyright notice in the Description page of Project Settings.


#include "RotateActor.h"

// Sets default values for this component's properties
URotateActor::URotateActor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void URotateActor::RotateMesh(FVector LookAtTarget, UStaticMeshComponent* RotateMesh)
{
	//Update TurretMesh rotation to face towards the LookAtTarget passed in 
	//TurretMesh -> SetWorldRotation()
	FVector LookAtTargetClean = FVector(LookAtTarget.X, LookAtTarget.Y, RotateMesh->GetComponentLocation().Z);
	FVector StartLocation = RotateMesh->GetComponentLocation();
	FRotator TurretRotation = FVector(LookAtTargetClean - StartLocation).Rotation();
	RotateMesh->SetWorldRotation(TurretRotation);
}

// Called when the game starts
void URotateActor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}
