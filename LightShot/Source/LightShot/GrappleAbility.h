// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CableActor.h"
#include "CableComponent.h"
#include "GrappleAbility.generated.h"

class UGrappleTargetComponent;
class AGrappleHook;
class USceneComponent;
class ACableActor;
class UCableComponent;

UENUM(BlueprintType)
enum GrappleState
{
	Retracted UMETA(DisplayName = "Retracted"), 
	Firing UMETA(DisplayName = "Firing"),
	Attatched UMETA(DisplayName = "Attached"),
	Released UMETA(DisplayName = "Released")
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class LIGHTSHOT_API UGrappleAbility : public UActorComponent
{
	GENERATED_BODY()
private:
	void GatherTargets();
	UGrappleTargetComponent* FindBestTarget(TArray<AActor*> &outActors);

	AActor* OwningCharacter = nullptr;
	UGrappleTargetComponent* BestTarget = nullptr;
	FVector CurrentDirection;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Sets default values for this component's properties
	UGrappleAbility();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void TryGrapple();
	GrappleState CurrentGrappleState;
	UGrappleTargetComponent* GrappleTarget = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grapple Hook Components", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGrappleHook> ProjectileClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grapple Hook Components", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACableActor> CableClass;

};
