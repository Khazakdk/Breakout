
// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutGameMode.h"
#include "PaddlePawn.h"
#include "BreakoutPC.h"

ABreakoutGameMode::ABreakoutGameMode()
{
	// change certain gamemode defaults like in the gamemode blueprint
	DefaultPawnClass = APaddlePawn::StaticClass();
	PlayerControllerClass = ABreakoutPC::StaticClass();
}