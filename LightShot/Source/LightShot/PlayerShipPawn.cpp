// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerShipPawn.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "MoveActor.h"
#include "RotateActor.h"
#include "LightShotProjectile.h"

const FName APlayerShipPawn::MoveForwardBinding("MoveForward");
const FName APlayerShipPawn::MoveRightBinding("MoveRight");

// Sets default values
APlayerShipPawn::APlayerShipPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	MoveActorComponent = CreateDefaultSubobject<UMoveActor>(TEXT("Movement Component"));
	RotateActorComponent = CreateDefaultSubobject<URotateActor>(TEXT("Rotation Component"));
}

// Called when the game starts or when spawned
void APlayerShipPawn::BeginPlay()
{
	Super::BeginPlay();
	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void APlayerShipPawn::GetInput()
{
	// Find movement direction
	ForwardValue = GetInputAxisValue(MoveForwardBinding);
	RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	MoveDirection = FVector(ForwardValue, RightValue, 0.f);//.GetClampedToMaxSize(1.0f);
}

void APlayerShipPawn::FireWeapon()
{
	FVector SpawnLocation = FireSpawnPoint->GetComponentLocation();
	FRotator SpawnRotation = FireSpawnPoint->GetComponentRotation();
	// spawn the projectile
	GetWorld()->SpawnActor<ALightShotProjectile>(SpawnLocation, SpawnRotation);
}

// Called every frame
void APlayerShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetInput();
	MoveActorComponent->CalculateMovement(DeltaTime, MoveDirection);
	if (PlayerControllerRef) {
		FHitResult TraceHitResult;
		PlayerControllerRef->GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResult);
		FVector HitLocation = TraceHitResult.ImpactPoint;

		RotateActorComponent->RotateMesh(HitLocation, ShipMesh);
	}
}

// Called to bind functionality to input
void APlayerShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerShipPawn::FireWeapon);
}

