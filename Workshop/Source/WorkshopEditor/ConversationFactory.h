#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ConversationFactory.generated.h"

/**
 * 
 */
UCLASS()
class WORKSHOPEDITOR_API UConversationFactory : public UFactory
{
	GENERATED_BODY()

public:
	UConversationFactory();
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
