// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoveActor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LIGHTSHOT_API UMoveActor : public UActorComponent
{
	GENERATED_BODY()

private:	
	void Move();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	FVector Movement;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 200.f;

public:	
	// Sets default values for this component's properties
	UMoveActor();
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void CalculateMovement(float DeltaSeconds, FVector Movement);
		
};
