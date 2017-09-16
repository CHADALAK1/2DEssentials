// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperCharacter.h"
#include "BaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MARIOWORLD_API ABaseCharacter : public APaperCharacter
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Health)
	int32 GetHealth() const { return Health; }


	UFUNCTION(BlueprintCallable, Category = BaseCharacter)
	bool IsDead() const { return bIsDead; }

private:

	int32 Health;

	bool bIsDead;
	
};
