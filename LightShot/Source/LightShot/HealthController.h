// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthController.generated.h"

class AMainGameMode;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTSHOT_API UHealthController : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(EditAnywhere)
	float DefaultHealth = 100.f;
	float Health = 0.0f;
	AMainGameMode* GameMode;

public:	
	// Sets default values for this component's properties
	UHealthController();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);		
};
