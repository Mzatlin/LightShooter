// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "LightShotPawn.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawn.h"

AMainGameMode::AMainGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ALightShotPawn::StaticClass();
}

void AMainGameMode::HandleShipDestroyed(AActor * ship)
{

	AShipPawnBase* shipActor = Cast<AShipPawnBase>(ship);
	if (!shipActor)
		return;

	shipActor->KillShip();

	APlayerShipPawn* player = Cast<APlayerShipPawn>(ship);
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("Insert Game Ending Logic Here"));
	}
}