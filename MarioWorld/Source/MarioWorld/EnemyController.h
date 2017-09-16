// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyController.generated.h"

/**
 * 
 */
UCLASS()
class MARIOWORLD_API AEnemyController : public AAIController
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = Move)
	void MoveToWaypoint(AActor *NewPoint);

private:
	
	
};
