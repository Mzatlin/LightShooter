// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GrappleTargetComponent.generated.h"

class AGrappleTargetActor;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTSHOT_API UGrappleTargetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrappleTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	class UBillboardComponent* BillboardComponent;
	AGrappleTargetActor* TargetActor;



public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetTargetActive(bool bActive);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grapple Target", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AGrappleTargetActor> TargetClass;
		
};
