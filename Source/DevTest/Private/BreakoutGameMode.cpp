
// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutGameMode.h"
#include "Brick.h"
#include "Internationalization/Text.h"
#include "Kismet/GameplayStatics.h"

ABreakoutGameMode::ABreakoutGameMode()
{
	LivesAtStart, LivesLeft = 5;
	BricksBroken, TotalBricks = 0;
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
			HudWidget->SetTxtBrickBrokenCounter(FText::FromString(FString::FromInt(BricksBroken)));
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

void ABreakoutGameMode::LoadLevel(FName levelName)
{
	FLatentActionInfo latentInfo(0, 0, TEXT("BindBrickDelegates"), this);
	UGameplayStatics::LoadStreamLevel(GetWorld(), levelName, true, true, latentInfo);
	LivesLeft = LivesAtStart;
	BricksBroken = 0;
}

void ABreakoutGameMode::BindBrickDelegates()
{
	TArray<AActor*> brickActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABrick::StaticClass(), brickActors);
	UE_LOG(LogTemp, Warning, TEXT("Binding %i bricks"), brickActors.Num());
	TotalBricks = brickActors.Num();
	for (AActor* actor : brickActors)
	{
		ABrick* brick = Cast<ABrick>(actor);
		if (brick != nullptr)
		{
			brick->DestroyedNotifier.AddDynamic(this, &ABreakoutGameMode::OnBrickDestroyed);
		}
	}
}

void ABreakoutGameMode::OnBrickDestroyed()
{
	UE_LOG(LogTemp, Warning, TEXT("Brick destroyed"));
	BricksBroken++;
	if (HudWidget != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("incremeting counter"));
		HudWidget->SetTxtBrickBrokenCounter(FText::FromString(FString::FromInt(BricksBroken)));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("not incremeting counter, no hud widget"));
	}
	if (BricksBroken >= TotalBricks)
	{
		// todo: implement some sort of linked list(?) to load next instead of hardcoding
		LoadLevel("Sublevel_B");
	}
}



 
// possibly handle brick spawning (certainly need a way to track bricks to track counts)
// I'm more okay with leaving the above point in the level blueprint, along with next level trigger
// individual brick counts are level specific, so is level order so appropriate to use level blueprint
// move ball spawn from PC to gamemode, then handle powerup spawns
// ball death is the big one
// also might be a good spot to insert a save function