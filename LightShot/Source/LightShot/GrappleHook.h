// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightShotProjectile.h"
#include "GrappleHook.generated.h"

class UGrappleTargetComponent;
class UIGrappledResponse;

UCLASS()
class LIGHTSHOT_API AGrappleHook : public ALightShotProjectile
{
	GENERATED_BODY()
	
private:
	FVector TargetLocation;
	FVector Direction;
	FVector CurrentTargetLocation;
	FVector StartLocation;
	AActor* TargetActor;
	AActor* OwningActor;
	float HookSpeed = 4000.f;
	bool isAttached = false;
	bool isRetrieved = false;
	UStaticMeshComponent* TargetMesh;
	void TryAttachGrappleHook();

public:	
	// Sets default values for this actor's properties
	AGrappleHook();
	void SetDirectionToTarget(UGrappleTargetComponent* grappleTarget);
	void ReturnDirectionToSender();
	bool GetAttachState();
	void SetAttachState(bool state); 
	void TryDetatchGrappleHook();
	void DetatchHook();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
