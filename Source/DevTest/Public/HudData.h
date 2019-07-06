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

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Text")
	FText TxtLevelCounter;
	
};
