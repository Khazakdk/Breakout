// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutPC.h"
#include "PaddlePawn.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

ABreakoutPC::ABreakoutPC() 
{
	BallLaunched = false;
}

void ABreakoutPC::SetupInputComponent()
{
	Super::SetupInputComponent();
	EnableInput(this);
	InputComponent->BindAction("Launch", IE_Pressed, this, &ABreakoutPC::Launch);
	InputComponent->BindAction("Pause", IE_Pressed, this, &ABreakoutPC::Pause);
	InputComponent->BindAxis("MoveHorizontal", this, &ABreakoutPC::MoveHorizontal);
}

void ABreakoutPC::Launch()
{
	if (BallLaunched == false)
	{
		UE_LOG(LogTemp, Warning, TEXT("Sending launch ball"));
		BallLaunched = true;
		Ball->Launch();
	}
}

void ABreakoutPC::Pause()
{
	if (PauseMenuWidgetClass != nullptr)
	{
		PauseMenuWidget = CreateWidget<UUserWidget>(GetWorld(), PauseMenuWidgetClass);
		if (PauseMenuWidget != nullptr)
		{
			SetPause(true);
			PauseMenuWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create pause menu"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No pause menu class selected in blueprint"));
	}
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
	if (ABallClass) 
	{
		Ball = GetWorld()->SpawnActor<ABall>(ABallClass, spawnLocation, rotation, spawnInfo);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Ball blueprint not set!  Not spawning ball"));
	}

	// get camera after spawning ball
	TArray<AActor*> cameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), cameraActors);
	if (cameraActors.Num() > 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("More than one camera actor found!  Only one camera actor should exist in the level"));
	}

	FViewTargetTransitionParams Params;
	SetViewTarget(cameraActors[0], Params);
}