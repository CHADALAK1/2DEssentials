// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "Enemy.generated.h"

/**
 * 
 */
UCLASS()
class MARIOWORLD_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	AEnemy();

	UPROPERTY(EditDefaultsOnly, Category = AI)
	class UBlackboardComponent *EnemyBlackboard;

private:
	
	
	
};