// Copyright Epic Games, Inc. All Rights Reserved.


#include "LetsGoGambHoleIngPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "LetsGoGambHoleIngCameraManager.h"

ALetsGoGambHoleIngPlayerController::ALetsGoGambHoleIngPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ALetsGoGambHoleIngCameraManager::StaticClass();
}

void ALetsGoGambHoleIngPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
