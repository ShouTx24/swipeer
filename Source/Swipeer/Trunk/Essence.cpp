// Property of Kamil Bochenski. All right's reserved.


#include "Essence.h"
#include "UObject/ConstructorHelpers.h"

UEssence::UEssence(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UParticleSystem>Particle(TEXT("/Game/Trunk/Essence/EssencePoint"));
	SetTemplate(Particle.Object);
}
