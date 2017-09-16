// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MarioPC.generated.h"

/**
 * 
 */
UCLASS()
class MARIOWORLD_API AMarioPC : public APlayerController
{
	GENERATED_BODY()

private:
	int32 Coins;
	int32 Lives;

public:

	AMarioPC();

	UFUNCTION(BlueprintCallable, Category = Lives)
	void AddLife();

	UFUNCTION(BlueprintCallable, Category = Lives)
	void RemoveLife();

	UFUNCTION(BlueprintCallable, Category = Lives)
	int32 GetLives() const { return Lives; }

	UFUNCTION(BlueprintCallable,Category = Coins)
	void AddCoin();

	void CheckCoinAmount();

	UFUNCTION(BlueprintCallable, Category = Coins)
	int32 GetCoins() const { return Coins; }
	
	
};
