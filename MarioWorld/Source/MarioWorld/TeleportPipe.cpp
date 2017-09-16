// Fill out your copyright notice in the Description page of Project Settings.

#include "TeleportPipe.h"
#include "MarioWorldCharacter.h"

ATeleportPipe::ATeleportPipe()
{
	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->AttachToComponent(Sprite, FAttachmentTransformRules::KeepRelativeTransform, "");
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &ATeleportPipe::OnCollisionEnter);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &ATeleportPipe::OnCollisionExit);

	TeleportExit = CreateDefaultSubobject<USceneComponent>(TEXT("TeleportExit"));
	TeleportExit->AttachToComponent(Sprite, FAttachmentTransformRules::KeepRelativeTransform, "");
}


void ATeleportPipe::OnCollisionEnter(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult &SweepResults)
{
	AMarioWorldCharacter *Char = Cast<AMarioWorldCharacter>(OtherActor);
	if (Char)
	{
		Char->TeleportPipe = this;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "PipeTouch");
	}
}

void ATeleportPipe::OnCollisionExit(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex)
{
	AMarioWorldCharacter *Char = Cast<AMarioWorldCharacter>(OtherActor);
	if (Char)
	{
		Char->TeleportPipe = NULL;
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Red, "PipeExit");
	}
}