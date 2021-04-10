// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipPawnBase.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AShipPawnBase::AShipPawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Collider"));
	RootComponent = CollisionComponent;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMeshComp(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship Mesh"));
	ShipMesh->SetupAttachment(RootComponent);
	ShipMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMesh->SetStaticMesh(ShipMeshComp.Object);
	FireSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawnpoint"));
	FireSpawnPoint->SetupAttachment(ShipMesh);
}

// Called when the game starts or when spawned
void AShipPawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShipPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

