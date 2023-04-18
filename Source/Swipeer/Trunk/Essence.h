// Property of Kamil Bochenski. All right's reserved.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"

#include "Essence.generated.h"

UCLASS(ClassGroup = "Points", meta = (BlueprintSpawnableComponent))
class SWIPEER_API UEssence : public UParticleSystemComponent
{
	GENERATED_BODY()
public:
	UEssence();
	virtual void BeginPlay() override;
	
	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
