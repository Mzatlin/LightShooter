// Copyright Epic Games, Inc. All Rights Reserved.

#include "LightShotGameMode.h"
#include "LightShotPawn.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawn.h"

ALightShotGameMode::ALightShotGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ALightShotPawn::StaticClass();
}

void ALightShotGameMode::HandleDeadActor(AActor * ship)
{
	AShipPawnBase* shipActor = Cast<AShipPawnBase>(ship);
	if (!shipActor)
		return;
	
	shipActor->KillShip();	

	APlayerShipPawn* player = Cast<APlayerShipPawn>(ship);
	if (player) {
		UE_LOG(LogTemp, Warning, TEXT("The Player Has Died"));
	}


}

