// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretPawn.h"
#include "RotateActor.h"
#include "LightShotProjectile.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATurretPawn::ATurretPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ATurretPawn::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &ATurretPawn::CheckAttackCondition, fireRate, true);
}

void ATurretPawn::CheckAttackCondition()
{
	if(PlayerPawn && GetPlayerDistance() < aggroDistance)
		Attack();
}

// Called every frame
void ATurretPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PlayerPawn && GetPlayerDistance() < aggroDistance)
		RotateActorComponent->RotateMesh(PlayerPawn->GetActorLocation(), TurretMesh);
}

void ATurretPawn::Attack()
{
	FVector SpawnLocation = FireSpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = FireSpawnPoint->GetComponentRotation();
	// spawn the projectile
	if (ProjectileClass) {
		ALightShotProjectile* TempProjectile = GetWorld()->SpawnActor<ALightShotProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		TempProjectile->SetOwner(this);
	}
}

