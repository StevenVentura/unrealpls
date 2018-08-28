// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"


// Sets default values
AGameplayCharacter::AGameplayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->RelativeLocation = FVector(-39.56f, 1.75f, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//jumping
	//https://forums.unrealengine.com/development-discussion/c-gameplay-programming/88247-implementing-jump
	/*GetCharacterMovement()->GravityScale = 2.5f;
	GetCharacterMovement()->JumpZVelocity = 620;*/



	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->RelativeRotation = FRotator(1.9f, -19.19f, 5.2f);
	Mesh1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
	this->AutoPossessPlayer = EAutoReceiveInput::Player0;
	this->AutoReceiveInput = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AGameplayCharacter::BeginPlay()
{
	Super::BeginPlay();
	Mesh1P->SetHiddenInGame(false, true);
}

// Called every frame
void AGameplayCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetActorLocation().Z < -300.f)
	{
		SetActorLocation(FVector(-104.940933f, -30.198050f, 187.929626f));
	}
	
}

void AGameplayCharacter::MoveForward(float value)
{
	if (value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), value);
	//	UE_LOG(LogTemp, Warning, TEXT("bELLIE, sekai! "));
	}
}

void AGameplayCharacter::MoveRight(float value)
{
	if (value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), value);
	}
}
void AGameplayCharacter::WTurnBoy(float value)
{
	if (value == 0.f) return;
	
	AddControllerYawInput(value);


}
void AGameplayCharacter::VTurnBoy(float value)
{
	if (value == 0.f) return;

	AddControllerPitchInput(-1*value);
}


void AGameplayCharacter::StopJumping()
{
	bPressedJump = false;
	ResetJumpState();
}

//
//#define SLOG(Format)
//{
//
//
//
//}

// Called to bind functionality to input
void AGameplayCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	UE_LOG(LogTemp, Warning, TEXT("666"));
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up gameplay key bindings
	check(PlayerInputComponent);
	// Bind movement events
	UE_LOG(LogTemp, Warning, TEXT("303"));
	PlayerInputComponent->BindAxis("MoveForward", this, &AGameplayCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGameplayCharacter::MoveRight);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAxis("Jump", this, &AGameplayCharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &AGameplayCharacter::StopJumping);

	PlayerInputComponent->BindAxis("TurnW", this, &AGameplayCharacter::WTurnBoy);
	PlayerInputComponent->BindAxis("TurnV", this, &AGameplayCharacter::VTurnBoy);
	// Bind jump events
	
	/*PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);*/

}

