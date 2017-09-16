// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"
#include "BaseCharacter.h"
#include "TeleportPipe.h"
#include "MarioWorldCharacter.generated.h"

class UTextRenderComponent;

USTRUCT(BlueprintType)
struct FCameraConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraConfig)
	bool bCanMoveZAxis;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraConfig)
	bool bCanMoveXAxis;
};

UENUM(BlueprintType)
enum class EAnimState : uint8
{
	E_Idle			UMETA(DisplayName="Idle"),
	E_Jumping		UMETA(DisplayName = "Jumping"),
	E_Running		UMETA(DisplayName="Running"),
	E_Crouching		UMETA(DisplayName="Crouching"),
	E_Teleporting	UMETA(DisplayName="Teleporting"),
};

/**
 * This class is the default character for MarioWorld, and it is responsible for all
 * physical interaction between the player and the world.
 *
 * The capsule component (inherited from ACharacter) handles collision with the world
 * The CharacterMovementComponent (inherited from ACharacter) handles movement of the collision capsule
 * The Sprite component (inherited from APaperCharacter) handles the visuals
 */
UCLASS(config=Game)
class AMarioWorldCharacter : public ABaseCharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera, meta=(AllowPrivateAccess="true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	UTextRenderComponent* TextComponent;
	virtual void Tick(float DeltaSeconds) override;
protected:
	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Animations)
	class UPaperFlipbook* RunningAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* IdleAnimation;

	// The animation to play while jumping (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
	class UPaperFlipbook* JumpUpAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
	class USoundBase* JumpSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CameraConfig)
	FCameraConfig CameraConfig;

	/** Called to choose the correct animation to play based on the character's movement state */
	void UpdateAnimation();

	/** Called for side to side input */
	void MoveRight(float Value);

	void UpdateCharacter();

	virtual void Jump() override;

	void LookUp();

	void PressedCrouch();

	void ReleaseCrouch();

	UAudioComponent* PlayPlayerSound(USoundBase *Sound);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface

public:
	AMarioWorldCharacter();

	ATeleportPipe *TeleportPipe;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	EAnimState AnimState;

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
