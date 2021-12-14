#pragma once

#include "Modules/ModuleInterface.h"

class FWorkshopEditorModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
