// Fill out your copyright notice in the Description page of Project Settings.


#include "HudData.h"

FText UHudData::GetTxtLevelCounter()
{
	return FText();
}

void UHudData::SetTxtLevelCounter(FText newLevelCounterText)
{
	TxtLevelCounter = newLevelCounterText;
}
