// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"
#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole LocalRole = InPawn->GetLocalRole();
	FString LRole;
	switch (LocalRole)
	{
	case ENetRole::ROLE_None:
		LRole = FString("None");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		LRole = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		LRole = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_Authority:
		LRole = FString("Authority");
		break;
	case ENetRole::ROLE_MAX:
		LRole = FString("Role Max");
		break;
	default:
		LRole = FString("Default");
		break;
	}
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString RRole;
	switch (RemoteRole)
	{
	case ENetRole::ROLE_None:
		RRole = FString("None");
		break;
	case ENetRole::ROLE_SimulatedProxy:
		RRole = FString("Simulated Proxy");
		break;
	case ENetRole::ROLE_AutonomousProxy:
		RRole = FString("Autonomous Proxy");
		break;
	case ENetRole::ROLE_Authority:
		RRole = FString("Authority");
		break;
	case ENetRole::ROLE_MAX:
		RRole = FString("Role Max");
		break;
	default:
		RRole = FString("Default");
		break;
	}

	FString RoleString = FString::Printf(TEXT("Local Role: %s, Remote Role: %s"), *LRole, *RRole);
	SetDisplayText(RoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
