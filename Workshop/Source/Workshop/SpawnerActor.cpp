// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnerActor.h"
#include "Engine/DocumentationActor.h"
#include <Runtime/Engine/Public/DrawDebugHelpers.h>

// Sets default values
ASpawnerActor::ASpawnerActor() : Offset(FVector(0.f, 0.f, 100.f)) {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASpawnerActor::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ASpawnerActor::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

#if WITH_EDITOR
  if (!IsSelectedInEditor())
    return;

  FTransform offsetTransform = Offset * GetTransform();
  FVector startPos = GetTransform().GetTranslation();
  FVector endPos = offsetTransform.GetTranslation();

  FColor col = ClassToSpawn_IsSelected ? ClassToSpawn_SelectedColor
                                       : ClassToSpawn_UnSelectedColor;

  DrawDebugDirectionalArrow(GetWorld(), startPos, endPos, 300.f, col, false,
                            (-1.0f), (uint8)'\000', 2.0f);
  DrawDebugPoint(GetWorld(), endPos, 20.f, col, false, -1.0f, (uint8)'\000');
#endif
}

#if WITH_EDITOR
void ASpawnerActor::PostEditChangeProperty(FPropertyChangedEvent &Event) {
  if (Event.GetPropertyName() ==
      GET_MEMBER_NAME_CHECKED(ASpawnerActor, ClassToSpawn))
    ClassToSpawn_IsSelected = ClassToSpawn.Get() != nullptr;

  Super::PostEditChangeProperty(Event);
}
#endif

inline void ASpawnerActor::SpawnStuff() {
  FTransform spawnedTransform = Offset * GetTransform();
  ClassToSpawn_Instance =
      GetWorld()->SpawnActor<AActor>(ClassToSpawn, spawnedTransform);
  OnActorSpawned(true);
}

void ASpawnerActor::DestroyStuff() {
  OnActorSpawned(false);
  ClassToSpawn_Instance->Destroy();
  ClassToSpawn_Instance = nullptr;
}

bool ASpawnerActor::IsStuffSpawned() const {
  return ClassToSpawn_Instance != nullptr;
}
