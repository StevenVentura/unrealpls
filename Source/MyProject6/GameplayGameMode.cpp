// Fill out your copyright notice in the Description page of Project Settings.

#include "GameplayGameMode.h"

AGameplayGameMode::AGameplayGameMode() : Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Script/MyProject6/GameplayCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	//HUDClass = AGameplayHUD::StaticClass();

}


