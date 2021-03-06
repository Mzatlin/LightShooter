// Fill out your copyright notice in the Description page of Project Settings.
#include "GrappleTargetComponent.h"
#include "GrappleTargetActor.h"

// Sets default values for this component's properties
UGrappleTargetComponent::UGrappleTargetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UGrappleTargetComponent::BeginPlay()
{
	Super::BeginPlay();
	FRotator SpawnRotation = FRotator(0, 0, 0);
	TargetActor = GetWorld()->SpawnActor<AGrappleTargetActor>(TargetClass, GetOwner()->GetActorLocation(), SpawnRotation);
	if (TargetActor) {
		TargetActor->AttachToComponent(GetOwner()->GetRootComponent(),
			FAttachmentTransformRules(
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				EAttachmentRule::SnapToTarget,
				true));
	}


	// ...
}


// Called every frame
void UGrappleTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UGrappleTargetComponent::SetTargetActive(bool bActive)
{
	if (TargetActor) {
		TargetActor->SetTargetUIActive(bActive);
	}
}

