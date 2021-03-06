// Copyright Epic Games, Inc. All Rights Reserve

#include "LightShotProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/StaticMesh.h"

ALightShotProjectile::ALightShotProjectile() 
{
	PrimaryActorTick.bCanEverTick = false;
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh"));
	ProjectileMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ProjectileMesh->SetupAttachment(RootComponent);
	ProjectileMesh->BodyInstance.SetCollisionProfileName("Projectile");
	ProjectileMesh->OnComponentHit.AddDynamic(this, &ALightShotProjectile::OnHit);		// set up a notification for when this component hits something
	RootComponent = ProjectileMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = ProjectileMesh;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void ALightShotProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AActor* OwningActor = GetOwner();

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if(OwningActor && OtherActor != OwningActor)
		{
			//Add Damage Code Here
			UGameplayStatics::ApplyDamage(OtherActor, Damage, OwningActor->GetInstigatorController(), this, DamageType);
		}
		// Only add impulse and destroy projectile if we hit a physics
		if (OtherComp->IsSimulatingPhysics()) 
		{
			OtherComp->AddImpulseAtLocation(GetVelocity() * 5.0f, GetActorLocation());
		}
	}

	Destroy();
}