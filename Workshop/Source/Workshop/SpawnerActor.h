// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnerActor.generated.h"

UCLASS()
class WORKSHOP_API ASpawnerActor : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ASpawnerActor();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  bool ShouldTickIfViewportsOnly() const override { return true; }

  UFUNCTION(BlueprintImplementableEvent)
  void OnActorSpawned(bool bSpawned);

private:
  UPROPERTY(EditAnywhere, Category = "Spawner")
  FTransform Offset;

  UPROPERTY(EditAnywhere, Category = "Spawner")
  TSubclassOf<AActor> ClassToSpawn;

  UFUNCTION(BlueprintCallable)             // Coin spawning
  void SpawnStuff();                       //
  UFUNCTION(BlueprintCallable)             //
  void DestroyStuff();                     //
  UFUNCTION(BlueprintCallable)             //
  bool IsStuffSpawned() const;             //
  AActor *ClassToSpawn_Instance = nullptr; //

#if WITH_EDITOR
  FColor ClassToSpawn_SelectedColor = FColor::Green;
  FColor ClassToSpawn_UnSelectedColor = FColor::Red;
  bool ClassToSpawn_IsSelected = false;
  virtual void PostEditChangeProperty(FPropertyChangedEvent &Event) override;
#endif
};
