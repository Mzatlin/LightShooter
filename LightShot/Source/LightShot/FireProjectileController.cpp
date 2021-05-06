// Fill out your copyright notice in the Description page of Project Settings.


#include "FireProjectileController.h"
#include "LightShotProjectile.h"
// Sets default values for this component's properties
UFireProjectileController::UFireProjectileController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UFireProjectileController::LaunchProjectile(TSubclassOf<ALightShotProjectile> projectileclass, FVector direction, FRotator rotation)
{
	if (projectileclass) {
		ALightShotProjectile* TempProjectile = GetWorld()->SpawnActor<ALightShotProjectile>(projectileclass, direction, rotation);
	}
	else 
	{
		UE_LOG(LogTemp, Warning, TEXT("No Projectile Class Found"));
	}
}
