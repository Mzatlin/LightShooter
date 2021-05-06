// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LightShotGameMode.generated.h"

UCLASS(MinimalAPI)
class ALightShotGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ALightShotGameMode();
	void HandleShipDestroyed(AActor* ship);
};



