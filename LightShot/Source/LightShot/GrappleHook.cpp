// Fill out your copyright notice in the Description page of Project Settings.


#include "GrappleHook.h"
#include "LightShotProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "IGrappledResponse.h"
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
		CurrentTargetLocation = TargetMesh->GetComponentLocation();
	}
}

void AGrappleHook::ReturnDirectionToSender()
{
	isRetrieved = true;
	Direction = (StartLocation - GetActorLocation()).GetSafeNormal(0.001);
	ProjectileMovement->Velocity = (Direction * HookSpeed);
}
bool AGrappleHook::GetAttachState()
{
	return isAttached;
}
void AGrappleHook::SetAttachState(bool state)
{
	isAttached = state;
}
// Called when the game starts or when spawned
void AGrappleHook::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AGrappleHook::TryAttachGrappleHook()
{
	if (!isAttached && FVector::DistSquared(GetActorLocation(), StartLocation) >= FVector::DistSquared(GetActorLocation(), TargetLocation))
	{
		SetActorLocation(TargetLocation);
		ProjectileMovement->Velocity = FVector::ZeroVector;
		TargetActor->AttachToActor(this,
			FAttachmentTransformRules(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::KeepWorld,
				EAttachmentRule::KeepWorld,
				true));
		isAttached = true;
	}
}

void AGrappleHook::TryDetatchGrappleHook()
{
	if (isRetrieved && FVector::DistSquared(GetActorLocation(), StartLocation) <= returnRange)
	{
		CurrentTargetLocation = StartLocation;
		DetatchHook();

		if (TargetActor && TargetActor->GetClass()->ImplementsInterface(UIGrappledResponse::StaticClass()))
		{
			IIGrappledResponse::Execute_RespondToGrapple(TargetActor);
		}
	}
}

void AGrappleHook::DetatchHook()
{
	TargetActor->DetachFromActor(FDetachmentTransformRules(
		EDetachmentRule::KeepWorld,
		EDetachmentRule::KeepWorld,
		EDetachmentRule::KeepWorld,
		false));
	isAttached = false;
}

// Called every frame
void AGrappleHook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryAttachGrappleHook();
	TryDetatchGrappleHook();
	if (isAttached && !isRetrieved) 
	{
		CurrentTargetLocation = TargetActor->GetActorLocation();
		SetActorLocation(CurrentTargetLocation);
	}
	if (isRetrieved && !isAttached) {
		SetActorLocation(CurrentTargetLocation);
	}
}

