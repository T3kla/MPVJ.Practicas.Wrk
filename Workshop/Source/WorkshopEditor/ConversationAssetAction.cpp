// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationAssetAction.h"
#include "../Workshop/Conversation.h"

FConversationAssetAction::FConversationAssetAction()
{
}

FConversationAssetAction::~FConversationAssetAction()
{
}

FText FConversationAssetAction::GetName() const
{
	return FText::FromString(TEXT("Conversation Get Name"));
}

UClass* FConversationAssetAction::GetSupportedClass() const
{
	return UConversation::StaticClass();
}

FColor FConversationAssetAction::GetTypeColor() const
{
	return FColor::Orange;
}

uint32 FConversationAssetAction::GetCategories()
{
	return EAssetTypeCategories::UI | EAssetTypeCategories::Misc;
}

FText FConversationAssetAction::GetAssetDescription(const FAssetData& AssetData) const
{
	return FText::FromString(AssetData.AssetName.ToString() + TEXT(" es un Conversation Asset"));
}
