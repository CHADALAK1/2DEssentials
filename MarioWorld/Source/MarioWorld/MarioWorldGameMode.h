// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "GameFramework/GameModeBase.h"
#include "MarioWorldGameMode.generated.h"

/**
 * The GameMode defines the game being played. It governs the game rules, scoring, what actors
 * are allowed to exist in this game type, and who may enter the game.
 *
 * This game mode just sets the default pawn to be the MyCharacter asset, which is a subclass of MarioWorldCharacter
 */
UCLASS(minimalapi)
class AMarioWorldGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AMarioWorldGameMode();
};
