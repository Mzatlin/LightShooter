// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameMode.h"
#include "LightShotPawn.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawn.h"
#include "BreakableObject.h"
#include "PlayerControllerBase.h"
#include "Kismet/GameplayStatics.h"

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<APlayerControllerBase>(UGameplayStatics::GetPlayerController(this, 0));
	if (PlayerControllerRef)
	{
		PlayerControllerRef->SetPlayerActive(true);
	}

}

AMainGameMode::AMainGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ALightShotPawn::StaticClass();
}

void AMainGameMode::HandleDeadActor(AActor * ship)
{
	if (!ship)
		return;

	AShipPawnBase* shipActor = Cast<AShipPawnBase>(ship);
	if (shipActor) 
	{
		shipActor->KillShip();
		APlayerShipPawn* player = Cast<APlayerShipPawn>(ship);
		if (player && PlayerControllerRef) 
		{
			UE_LOG(LogTemp, Warning, TEXT("Insert Game Ending Logic Here"));
			PlayerControllerRef->SetPlayerActive(false);
		}
	}
	else
	{
		HandleBreakableActor(ship);
	}

}

void AMainGameMode::HandleBreakableActor(AActor * simple)
{
	ABreakableObject* breakActor = Cast<ABreakableObject>(simple);
	if (breakActor) {
		breakActor->HandleBreak();
	}


}
