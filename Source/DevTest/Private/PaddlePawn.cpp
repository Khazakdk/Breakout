// Fill out your copyright notice in the Description page of Project Settings.


#include "PaddlePawn.h"

// Sets default values
APaddlePawn::APaddlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->speed = 500.0;

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
	float xMagnitude = AxisValue * this->speed;
	Super::AddMovementInput(FVector(AxisValue, 0.0, 0.0), xMagnitude, false);
}

