// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MoveActorBase.h"
#include "Components/ActorComponent.h"
#include "MovePlayerShip.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTSHOT_API UMovePlayerShip : public UMoveActorBase
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovePlayerShip();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void CalculateMovement(float DeltaSeconds, FVector Movement);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
