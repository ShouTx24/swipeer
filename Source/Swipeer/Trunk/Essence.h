// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "../SwipeerGameModeBase.h"
#include "Essence.generated.h"

UCLASS(ClassGroup = "Points", meta = (BlueprintSpawnableComponent))
class SWIPEER_API UEssence : public UBoxComponent
{
	GENERATED_BODY()

	UEssence();
	
	virtual void BeginPlay() override;

	UStaticMeshComponent* VC;
	UParticleSystemComponent* ParticleComponent;

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
