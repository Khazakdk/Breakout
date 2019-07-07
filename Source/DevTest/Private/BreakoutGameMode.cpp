
// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutGameMode.h"
#include "Internationalization/Text.h"

ABreakoutGameMode::ABreakoutGameMode()
{
	LivesAtStart = 5;
	LivesLeft = 5;
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
			HudWidget->SetTxtLevelCounter(FText::FromString(TEXT("1")));
			HudWidget->SetTxtLifeCounter(FText::FromString(FString::FromInt(LivesLeft)));
			HudWidget->SetTxtBrickBrokenCounter(FText::FromString(TEXT("0")));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to create hud"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No hud class selected in blueprint"));
	}

	
}
 
// possibly handle brick spawning (certainly need a way to track bricks to track counts)
// I'm more okay with leaving the above point in the level blueprint, along with next level trigger
// individual brick counts are level specific, so is level order so appropriate to use level blueprint
// move ball spawn from PC to gamemode, then handle powerup spawns
// ball death is the big one
// also might be a good spot to insert a save function