// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
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

	UPROPERTY(EditDefaultsOnly, Category = AI)
	class UBlackboardComponent *EnemyBlackboard;

	UPROPERTY(EditDefaultsOnly, Category = AI)
	class UBehaviorTreeComponent *EnemyTree;

	UFUNCTION(BlueprintCallable, Category = Move)
	void MoveToWaypoint(AActor *NewPoint);

private:
	
	
};
