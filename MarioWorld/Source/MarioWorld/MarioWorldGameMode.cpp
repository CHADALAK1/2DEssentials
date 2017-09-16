// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "MarioWorldGameMode.h"
#include "MarioPC.h"
#include "MarioWorldCharacter.h"

AMarioWorldGameMode::AMarioWorldGameMode()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PC_BP(TEXT("/Game/2DSideScrollerCPP/Blueprints/Player/MarioPC_BP"));

	if (PC_BP.Succeeded())
	{
		PlayerControllerClass = PC_BP.Class;

	}
	// Set default pawn class to our character
	DefaultPawnClass = AMarioWorldCharacter::StaticClass();	
}
