// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IGrappledResponse.h"
#include "BreakableObject.generated.h"

UCLASS()
class LIGHTSHOT_API ABreakableObject : public AActor, public IIGrappledResponse
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void HandleBreak();
	virtual void RespondToGrapple_Implementation() override;
	virtual void ReelInResponse_Implementation() override;
};
