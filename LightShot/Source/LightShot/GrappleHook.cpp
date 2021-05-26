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
	return isRetrieved && !isAttached;
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
				EAttachmentRule::KeepRelative,
				true));
		isAttached = true;
	}
}

void AGrappleHook::TryDetatchGrappleHook()
{
	if (isRetrieved && FVector::DistSquared(GetActorLocation(), StartLocation) <= FVector::DistSquared(GetActorLocation(), TargetLocation))
	{
		CurrentTargetLocation = StartLocation;
		TargetActor->SetActorLocation(StartLocation);

		TargetActor->DetachFromActor(FDetachmentTransformRules(
			EDetachmentRule::KeepRelative,
			EDetachmentRule::KeepRelative, 
			EDetachmentRule::KeepRelative,
			true));


		//For now, the mesh will teleport to the start location 
		TargetMesh->SetWorldLocation(StartLocation+FVector(0,-10.f,0));
		TargetMesh->SetSimulatePhysics(false);
		TargetMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

		isAttached = false;
	}
}

// Called every frame
void AGrappleHook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TryAttachGrappleHook();
	TryDetatchGrappleHook();
	if (TargetMesh && !isRetrieved) 
	{
		CurrentTargetLocation = TargetMesh->GetComponentLocation();
	}
	if (isRetrieved) {
		CurrentTargetLocation = StartLocation;
	}
	SetActorLocation(CurrentTargetLocation);



}

