// Fill out your copyright notice in the Description page of Project Settings.


#include "ConversationComponent.h"
#include "Conversation.h"

// Sets default values for this component's properties
UConversationComponent::UConversationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	CurrentLine = 0;
	Conversation = nullptr;

	// ...
}


// Called when the game starts
void UConversationComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UConversationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UConversationComponent::ShowCurrentLine()
{
	if (Conversation == nullptr) return;
	if (CurrentLine < 0 || CurrentLine >= Conversation->Lines.Num()) return;

	const FConver& Line = Conversation->Lines[CurrentLine];

	GEngine->AddOnScreenDebugMessage(-1, Line.Duration, Line.Color, Line.Text);
}

void UConversationComponent::AdvanceConversation()
{
	if (Conversation == nullptr) return;
	if (CurrentLine < 0 || CurrentLine >= Conversation->Lines.Num()) return;

	const FConver& Line = Conversation->Lines[CurrentLine];

	CurrentLine += Line.Offset;
}

