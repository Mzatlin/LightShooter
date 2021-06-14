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
	Attatched UMETA(DisplayName = "Attatched"),
	HeadingToTarget UMETA(DisplayName = "HeadingToTarget"),
	Released UMETA(DisplayName = "Released")
};
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class LIGHTSHOT_API UGrappleAbility : public UActorComponent
{
	GENERATED_BODY()
private:
	void GatherTargets();
	UGrappleTargetComponent* FindBestTarget(TArray<AActor*> &outActors);
	void AttatchHookToTarget();
	void CleanUpHook();
	void HandleGrappledTarget();
	void MoveToTarget();

	AActor* OwningCharacter = nullptr;
	UGrappleTargetComponent* BestTarget = nullptr;
	FVector CurrentDirection;
	AGrappleHook* HookProjectile;
	ACableActor* Cable;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hook Options", meta = (AllowPrivateAccess = "true"))
	float returnRange = 14500.f;
	
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
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grapple Hook Components", meta = (AllowPrivateAccess = "true"))
	float GrappleRange = 800.f;
	
	bool isGrappled = false;

};
