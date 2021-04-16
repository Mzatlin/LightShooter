// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPawnBase.h"

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
	
}

// Called every frame
void AEnemyPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
