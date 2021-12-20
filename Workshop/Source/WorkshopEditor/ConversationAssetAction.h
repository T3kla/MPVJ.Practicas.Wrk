// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AssetTypeActions_Base.h"

/**
 *
 */
class WORKSHOPEDITOR_API FConversationAssetAction
    : public FAssetTypeActions_Base {
public:
  FConversationAssetAction();
  ~FConversationAssetAction();

  // Inherited via FAssetTypeActions_Base
  virtual FText GetName() const override;
  virtual UClass* GetSupportedClass() const override;
  virtual FColor GetTypeColor() const override;
  virtual uint32 GetCategories() override;
  virtual FText GetAssetDescription(const FAssetData& AssetData) const override;
};
