// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePawn.h"

// Sets default values
APaddlePawn::APaddlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Speed = 500.0;
	SmPaddle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SmPaddle"));
	RootComponent = SmPaddle;
	SmPaddle->SetSimulatePhysics(true);
	SmPaddle->SetConstraintMode(EDOFMode::XZPlane);
	SmPaddle->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SmPaddle->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingPawnMovement"))

}

// Called when the game starts or when spawned
void APaddlePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APaddlePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APaddlePawn::MoveHorizontal(float AxisValue)
{
	Super::AddMovementInput(FVector(AxisValue, 0.0, 0.0), AxisValue * Speed, false);
}

