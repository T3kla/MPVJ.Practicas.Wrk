#include "WorkshopEditorModule.h"

#include "Modules/ModuleManager.h"
#include "ConversationAssetAction.h"

IMPLEMENT_MODULE(FWorkshopEditorModule, WorkshopEditor)

void FWorkshopEditorModule::StartupModule()
{
	FAssetToolsModule& AssetToolsMod = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools");
	IAssetTools& AssetTools = AssetToolsMod.Get();
	
	ConversationActions = MakeShareable(new FConversationAssetAction());
	AssetTools.RegisterAssetTypeActions(ConversationActions.ToSharedRef());
}

void FWorkshopEditorModule::ShutdownModule()
{
	if (FModuleManager::Get().IsModuleLoaded("AssetTools"))
	{
		auto & AssetTools = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools").Get();

		AssetTools.UnregisterAssetTypeActions(ConversationActions.ToSharedRef());
	}
	ConversationActions.Reset();
} 
