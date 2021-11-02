// Property of Kamil Bochenski. All right's reserved.


#include "Essence.h"

UEssence::UEssence()
{
	this->InitBoxExtent(FVector(10, 10, 10));
	this->SetCollisionProfileName(FName("OverlapAll"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystem(TEXT("/Game/Trunk/Essence/EssencePoint"));
	ParticleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));
	ParticleComponent->SetTemplate(ParticleSystem.Object);
	ParticleComponent->SetupAttachment(this);
	this->OnComponentBeginOverlap.AddDynamic(this, &UEssence::OnOverlap);
}

void UEssence::BeginPlay()
{
	Super::BeginPlay();
	ParticleComponent->RegisterComponent();
}

void UEssence::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (GEngine)GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Point Gathered"));
}