// Fill out your copyright notice in the Description page of Project Settings.

#include "Hypoxia.h"
#include "Keycard.h"
#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"


AStaticMeshActor *Keycard;

AStaticMeshActor *Door;



void AKeycard::Tick(float DeltaTime) {

	Super::Tick(DeltaTime);

	if (FVector::Dist(Door->GetActorLocation(), Item->GetComponentLocation()) > 100.0f) {
		UnlockLock();
	}

}



void AKeycard::BeginPlay() {

	Super::BeginPlay();

	for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		AStaticMeshActor *Mesh = *ActorItr;
	

		if(ActorItr->ActorHasTag(FName("Keycard"))) {

			Keycard = *ActorItr;

			//UE_LOG(LogTemp, Warning, TEXT("Parent: %s"), *ActorItr->GetName());
		}
	}

	for (TActorIterator<AStaticMeshActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->ActorHasTag(FName("DDoor"))) {

			Door = *ActorItr;

			//UE_LOG(LogTemp, Warning, TEXT("Parent: %s"), *ActorItr->GetName());
			break;
		}
	}
}

	void AKeycard::UnlockLock()
	{
		Door->Destroy();
	}
