// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "EnemyPawnBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TurretPawn.generated.h"

class URotateActor;

UCLASS()
class LIGHTSHOT_API ATurretPawn : public AEnemyPawnBase
{
	GENERATED_BODY()

private:
	FTimerHandle FireRateTimerHandle;
public:
	// Sets default values for this pawn's properties
	ATurretPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void CheckAttackCondition() override;
	virtual void Attack() override;
	/*Rotation*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	URotateActor* RotateActorComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
