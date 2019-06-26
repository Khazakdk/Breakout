
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

// things gamemode or gamemode like class needs to do
// spawn camera, set camera, set UI
// expose these properties in blueprint for easy editing 
// possibly handle brick spawning (certainly need a way to track bricks to track counts)
// I'm more okay with leaving the above point in the level blueprint, along with next level trigger
// individual brick counts are level specific, so is level order so appropriate to use level blueprint
// move ball spawn from PC to gamemode, then handle powerup spawns
// ball death is the big one
// also might be a good spot to insert a save function