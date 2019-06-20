// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutPC.h"
#include "PaddlePawn.h"


ABreakoutPC::ABreakoutPC() 
{
	bBallLaunched = false;
	speed = 500.0;
	//spawn the ball at 10,0,40 above the possessed pawn
}

void ABreakoutPC::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Launch", IE_Pressed, this, &ABreakoutPC::Launch);
	InputComponent->BindAction("Pause", IE_Pressed, this, &ABreakoutPC::Pause);
	InputComponent->BindAxis("MoveHorizontal", this, &ABreakoutPC::MoveHorizontal);
}

void ABreakoutPC::Launch()
{
	if (bBallLaunched == false)
	{
		bBallLaunched = true;
		ball->Launch();
	}
}

void ABreakoutPC::Pause()
{
	// add code to call menu here
}

void ABreakoutPC::MoveHorizontal(float AxisValue)
{
	auto pawn = Cast<APaddlePawn>(GetPawn());
	if (pawn)
	{
		pawn->MoveHorizontal(AxisValue);
	}
}

void ABreakoutPC::BeginPlay()
{
	FVector spawnLocation(10.0, 0.0, 40.0);
	FRotator rotation(0.0, 0.0, 0.0);
	FActorSpawnParameters spawnInfo;
	ball = GetWorld()->SpawnActor<ABall>(spawnLocation, rotation, spawnInfo);
}

