// Fill out your copyright notice in the Description page of Project Settings.


#include "HudData.h"

FText UHudData::GetTxtLevelCounter()
{
	return TxtLevelCounter;
}

void UHudData::SetTxtLevelCounter(FText newLevelCounterText)
{
	TxtLevelCounter = newLevelCounterText;
}

FText UHudData::GetTxtLifeCounter()
{
	return TxtLifeCounter;
}

void UHudData::SetTxtLifeCounter(FText newLifeCounterText)
{
	TxtLifeCounter = newLifeCounterText;
}

FText UHudData::GetTxtBrickBrokenCounter()
{
	return TxtBrickBrokenCounter;
}

void UHudData::SetTxtBrickBrokenCounter(FText newBrickBrokenText)
{
	TxtBrickBrokenCounter = newBrickBrokenText;
}
