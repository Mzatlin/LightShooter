// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPawnBase.h"
#include "ShipPawnBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AEnemyPawnBase::AEnemyPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEnemyPawnBase::BeginPlay()
{
	Super::BeginPlay();
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
}

float AEnemyPawnBase::GetPlayerDistance()
{
	if (!PlayerPawn)
		return 0.f;
	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}

// Called every frame
void AEnemyPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

