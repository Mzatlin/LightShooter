// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ShipPawnBase.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EnemyPawnBase.generated.h"

class ALightShotProjectile;

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
	virtual void CheckAttackCondition() PURE_VIRTUAL(AEnemyPawnBase::CheckAttackCondition,);
	virtual void Attack() PURE_VIRTUAL(AEnemyPawnBase::Attack,);
	float GetPlayerDistance();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy Settings", meta = (AllowPrivateAccess = "true"))
	float aggroDistance = 3000;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Type", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ALightShotProjectile> ProjectileClass;
	APawn* PlayerPawn;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
