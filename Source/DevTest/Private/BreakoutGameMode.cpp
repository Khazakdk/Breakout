
// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutGameMode.h"
#include "PaddlePawn.h"
#include "BreakoutPC.h"
#include "HudData.h"

ABreakoutGameMode::ABreakoutGameMode()
{
	
}

void ABreakoutGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (HudWidgetClass != nullptr)
	{
		HudWidget = CreateWidget<UHudData>(GetWorld(), HudWidgetClass);
		if (HudWidget != nullptr)
		{
			HudWidget->AddToViewport();
			HudWidget->SetTxtLevelCounter(TEXT("1"));
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

// things gamemode or gamemode like class needs to do
// spawn camera, set camera, set UI
// expose these properties in blueprint for easy editing 
// possibly handle brick spawning (certainly need a way to track bricks to track counts)
// I'm more okay with leaving the above point in the level blueprint, along with next level trigger
// individual brick counts are level specific, so is level order so appropriate to use level blueprint
// move ball spawn from PC to gamemode, then handle powerup spawns
// ball death is the big one
// also might be a good spot to insert a save function