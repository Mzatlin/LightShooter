// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleHook.h"
#include "LightShotProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "GrappleTargetComponent.h"

// Sets default values
AGrappleHook::AGrappleHook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


void AGrappleHook::SetDirectionToTarget(UGrappleTargetComponent * grappleTarget)
{
	if (grappleTarget && grappleTarget->GetOwner())
	{
		TargetActor = grappleTarget->GetOwner();
		TargetLocation = TargetActor->GetActorLocation();
		Direction = (TargetLocation - GetActorLocation()).GetSafeNormal(0.001);
		ProjectileMovement->Velocity = (Direction * HookSpeed);
	}
}

// Called when the game starts or when spawned
void AGrappleHook::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AGrappleHook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FVector::DistSquared(GetActorLocation(), StartLocation) >= FVector::DistSquared(GetActorLocation(),TargetLocation))
	{
		SetActorLocation(TargetLocation);
	}
}

