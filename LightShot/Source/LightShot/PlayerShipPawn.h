// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ShipPawnBase.h"
#include "PlayerShipPawn.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UMoveActor;

UCLASS()
class LIGHTSHOT_API APlayerShipPawn : public AShipPawnBase
{
	GENERATED_BODY()

private:
	/** The camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

	/** Player Ship Movement */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UMoveActor* MoveActorComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	float ForwardValue;
	float RightValue;
	APlayerController* PlayerControllerRef;
	FVector MoveDirection;
public:
	// Sets default values for this pawn's properties
	APlayerShipPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void GetInput();
	void RotateMesh(FVector LookAtTarget);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Static names for axis bindings
	static const FName MoveForwardBinding;
	static const FName MoveRightBinding;
};
