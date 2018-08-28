// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayCharacter.generated.h"

UCLASS(config = Game)
class MYPROJECT6_API AGameplayCharacter : public ACharacter
{
	GENERATED_BODY()
		/** Pawn mesh: 1st person view (arms; seen only by self) */
		UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* Mesh1P;

		/** First person camera */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

public:
	// Sets default values for this character's properties
	AGameplayCharacter();

protected:
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveForward(float);
	void MoveRight(float);
	void WTurnBoy(float);
	void VTurnBoy(float);
	/*void Jump(float);*/
	void StopJumping();
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	
	
};
