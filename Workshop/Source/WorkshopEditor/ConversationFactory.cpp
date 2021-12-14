#include "ConversationFactory.h"
#include "../Workshop/Conversation.h"
#include "Misc/FeedbackContext.h"

UConversationFactory::UConversationFactory()
{
	SupportedClass = UConversation::StaticClass();
	bCreateNew = true;
}

 UObject* UConversationFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	 if(Warn->YesNof(FText::FromString(TEXT("Are you sure?"))))
		return NewObject<UConversation>(InParent, InClass, InName, Flags);
	 return nullptr;
 }