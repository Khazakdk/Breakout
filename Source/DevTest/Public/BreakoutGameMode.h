// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "BreakoutGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DEVTEST_API ABreakoutGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// default constructor 
	ABreakoutGameMode();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD Widget")
	TSubclassOf<class UHudData> HudWidgetClass;

	UHudData* HudWidget;

};
