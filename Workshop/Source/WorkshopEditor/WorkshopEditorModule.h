#pragma once

#include "Modules/ModuleInterface.h"

class FConversationAssetAction;

class FWorkshopEditorModule : public IModuleInterface
{
private:
	TSharedPtr <FConversationAssetAction> ConversationActions;
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
