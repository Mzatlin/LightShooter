// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "EnemyPawnBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TurretPawn.generated.h"

UCLASS()
class LIGHTSHOT_API ATurretPawn : public AEnemyPawnBase
{
	GENERATED_BODY()

private:
	FTimerHandle FireRateTimerHandle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Settings", meta = (AllowPrivateAccess = "true"))
	float fireRate = 1.f;
public:
	// Sets default values for this pawn's properties
	ATurretPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void CheckAttackCondition() override;
	void Attack() override;
	void HandleDeath() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
