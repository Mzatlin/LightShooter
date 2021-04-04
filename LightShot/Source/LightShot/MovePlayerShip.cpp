// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlayerShip.h"
#include "GameFramework/Actor.h"
// Sets default values for this component's properties
UMovePlayerShip::UMovePlayerShip()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}
// Called when the game starts
void UMovePlayerShip::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UMovePlayerShip::CalculateMovement(float DeltaSeconds, FVector MoveDirection)
{
	//Super::CalculateMovement(float DeltaSeconds);
	// Calculate  movement
	Movement = MoveDirection * MoveSpeed * DeltaSeconds;
}


// Called every frame
void UMovePlayerShip::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


