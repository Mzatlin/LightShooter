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
		TargetMesh = TargetActor->FindComponentByClass<UStaticMeshComponent>();
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

void AGrappleHook::TryAttachGrappleHook()
{
	if (FVector::DistSquared(GetActorLocation(), StartLocation) >= FVector::DistSquared(GetActorLocation(), TargetLocation))
	{
		SetActorLocation(TargetLocation);
		ProjectileMovement->Velocity = FVector::ZeroVector;
		TargetActor->AttachToActor(this,
			FAttachmentTransformRules(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				true));
		isAttached = true;
	}
}

// Called every frame
void AGrappleHook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!isAttached) {
		TryAttachGrappleHook();
	}
	else 
	{
		if (TargetMesh) 
		{
			SetActorLocation(TargetMesh->GetComponentLocation());
		}
	}

}

