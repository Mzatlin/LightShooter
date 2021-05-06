// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthController.h"
#include "MainGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthController::UHealthController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthController::BeginPlay()
{
	Super::BeginPlay();
	Health = DefaultHealth;
	GameMode= Cast<AMainGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthController::TakeDamage);
}

void UHealthController::TakeDamage(AActor * DamagedActor, float Damage, const UDamageType * DamageType, AController * InstigatedBy, AActor * DamageCauser)
{
	if (Health > 0 && Damage > 0) 
	{
		Health = FMath::Clamp(Health - Damage, 0.0f, DefaultHealth);
		UE_LOG(LogTemp, Warning, TEXT("Health: %f"), Health);
		if (Health <= 0) 
		{
			if (GameMode) {
				GameMode->HandleShipDestroyed(GetOwner());
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Unable to reference GameMode on %s"), *GetOwner()->GetName());
			}
		}
	}
}


// Called every frame
void UHealthController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

