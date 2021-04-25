// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShipPawnBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawnBase.generated.h"

UCLASS()
class LIGHTSHOT_API AEnemyPawnBase : public AShipPawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemyPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void CheckAttackCondition();
	virtual void Attack();
	float GetPlayerDistance();
	APawn* PlayerPawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
