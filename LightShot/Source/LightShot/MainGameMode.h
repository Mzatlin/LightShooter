// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainGameMode.generated.h"
class APlayerControllerBase;
/**
 * 
 */
UCLASS()
class LIGHTSHOT_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	APlayerControllerBase* PlayerControllerRef;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
public:
	AMainGameMode();
	void HandleDeadActor(AActor* ship);
	void HandleBreakableActor(AActor* simple);
};
