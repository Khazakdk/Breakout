// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutPC.h"

ABreakoutPC::ABreakoutPC() 
{
	bBallLaunched = false;
	speed = 500.0;
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
		// call dispatch here
	}
}

void ABreakoutPC::Pause()
{
}

void ABreakoutPC::MoveHorizontal(float AxisValue)
{
	auto pawn = Cast<APawn>(GetPawn());
	if (pawn)
	{
		pawn->MoveHorizontal(AxisValue);
	}
}

