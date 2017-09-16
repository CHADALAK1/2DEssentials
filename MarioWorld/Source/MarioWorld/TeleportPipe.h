// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PipeBase.h"
#include "TeleportPipe.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8
{
	E_Down		UMETA(DisplayName = "Down"),
	E_Up		UMETA(DisplayName = "Up"),
};

/**
 * 
 */
UCLASS()
class MARIOWORLD_API ATeleportPipe : public APipeBase
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent *Trigger;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision, meta = (AllowPrivateAccess = "true"))
	class USceneComponent *TeleportExit;

public:
	ATeleportPipe();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pipe)
	ATeleportPipe *EndPipe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pipe)
	EDirection Direction;

	UFUNCTION()
		void OnCollisionEnter(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult &SweepResults);

	UFUNCTION()
		void OnCollisionExit(UPrimitiveComponent *OverlappedComp, AActor *OtherActor, UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

	FORCEINLINE UBoxComponent *GetTrigger() const { return Trigger; }
	FORCEINLINE USceneComponent *GetTeleportExit() const { return TeleportExit; }

};
