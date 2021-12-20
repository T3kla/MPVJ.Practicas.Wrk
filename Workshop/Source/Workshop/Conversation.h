#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Conversation.generated.h"

USTRUCT(BlueprintType)
struct WORKSHOP_API FConver {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FString Text;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FColor Color;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Duration;
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int Offset;
};

UCLASS(BlueprintType)
class WORKSHOP_API UConversation : public UObject {
  GENERATED_BODY()

public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coversation")
  FString Name;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Coversation")
  TArray<FConver> Lines;
};
