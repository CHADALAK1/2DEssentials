// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyController.h"



void AEnemyController::MoveToWaypoint(AActor *NewPoint)
{
	if (!NewPoint)
		return;

	MoveToActor(NewPoint);
}
