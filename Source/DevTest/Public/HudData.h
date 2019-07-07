// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HudData.generated.h"

/**
 * 
 */
UCLASS()
class DEVTEST_API UHudData : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
	FText GetTxtLevelCounter();

	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
	void SetTxtLevelCounter(FText newLevelCounterText);

	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
	FText GetTxtLifeCounter();

	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
	void SetTxtLifeCounter(FText newLifeCounterText);

	UFUNCTION(BlueprintPure, Category = "Widgets|Text")
	FText GetTxtBrickBrokenCounter();

	UFUNCTION(BlueprintCallable, Category = "Widgets|Text")
	void SetTxtBrickBrokenCounter(FText newBrickBrokenText);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText TxtLevelCounter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText TxtLifeCounter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText TxtBrickBrokenCounter;

};
