// Fill out your copyright notice in the Description page of Project Settings.

#include "PipeBase.h"


// Sets default values
APipeBase::APipeBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	RootComponent = Sprite;

}

// Called when the game starts or when spawned
void APipeBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APipeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

