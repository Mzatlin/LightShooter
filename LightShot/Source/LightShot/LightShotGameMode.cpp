// Copyright Epic Games, Inc. All Rights Reserved.

#include "LightShotGameMode.h"
#include "LightShotPawn.h"

ALightShotGameMode::ALightShotGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = ALightShotPawn::StaticClass();
}

