// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActorBase.h"

// Sets default values for this component's properties
UMoveActorBase::UMoveActorBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveActorBase::BeginPlay()
{

}

void UMoveActorBase::CalculateMovement()
{

}

// Called every frame
void UMoveActorBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (canMove) 
	{
		CalculateMovement();
	}
}

