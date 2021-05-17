// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightShotProjectile.h"
#include "GrappleHook.generated.h"

class UGrappleTargetComponent;

UCLASS()
class LIGHTSHOT_API AGrappleHook : public ALightShotProjectile
{
	GENERATED_BODY()
	
private:
	FVector TargetLocation;
	FVector Direction;
	FVector StartLocation;
	AActor* TargetActor;
	float HookSpeed = 3000.f;
public:	
	// Sets default values for this actor's properties
	AGrappleHook();
	void SetDirectionToTarget(UGrappleTargetComponent* grappleTarget);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
