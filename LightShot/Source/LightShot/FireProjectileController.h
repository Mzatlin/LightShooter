// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FireProjectileController.generated.h"

class ALightShotProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTSHOT_API UFireProjectileController : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFireProjectileController();
	void LaunchProjectile(TSubclassOf<ALightShotProjectile> projectileclass, FVector direction, FRotator rotation);
		
};
