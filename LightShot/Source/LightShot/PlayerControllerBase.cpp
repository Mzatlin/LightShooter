// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerControllerBase.h"

void APlayerControllerBase::SetPlayerActive(bool isPlayerActive)
{
	isControllerActive = isPlayerActive;
	if (isControllerActive)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = isPlayerActive;

}