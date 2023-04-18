// Property of Kamil Bochenski. All right's reserved.


#include "Essence.h"

#include "Kismet/GameplayStatics.h"
#include "Swipeer/SwipeerGameModeBase.h"

UEssence::UEssence()
{
	SetCollisionProfileName(FName("OverlapAll"));
	
	ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystem(TEXT("/Game/Trunk/Essence/EssencePoint"));
	SetTemplate(ParticleSystem.Object);
	
	this->OnComponentBeginOverlap.AddDynamic(this, &UEssence::OnOverlap);
}

void UEssence::BeginPlay()
{
	Super::BeginPlay();
}

void UEssence::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Cast<ASwipeerGameModeBase>(UGameplayStatics::GetGameMode(GWorld))->GiveEssence();
	TArray<USceneComponent*> Children = GetAttachChildren();
	for (USceneComponent* ChildComponent : Children)
	{
		ChildComponent->DestroyComponent();
	}
	DestroyComponent();
}