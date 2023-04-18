// Property of Kamil Bochenski. All right's reserved.

#include "Trunk.h"
#include "TrunkCore.h"

ATrunk::ATrunk()
{
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
}

FMotive ATrunk::GetActiveMotive() const
{
	return ActiveMotive;
}

void ATrunk::ChangeToNextMotive()
{
	ActiveMotive = Motives.Num() <= ++ActiveMotiveID ? ActiveMotive : Motives[ActiveMotiveID];
}

void ATrunk::BeginPlay()
{
	Super::BeginPlay();

	ActiveMotive = Motives[0];
	
	while (PartCounter < TrunkLenght)
	{
		NewPart();
	}
}

void ATrunk::NewPart()
{
	UTrunkCore* NewPart = NewObject<UTrunkCore>(this);
	NewPart->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	NewPart->SetRelativeLocation(FVector(0,
		GetHead() ? GetHead()->GetRelativeLocation().Y + TrunkCoreMesh->GetBounds().BoxExtent.Y * 2 : 0,
		0));
	NewPart->SetStaticMesh(TrunkCoreMesh);
	NewPart->SetMaterial(0, GetActiveMotive().CoreMeshMaterial);
	NewPart->RegisterComponent();

	TrunkParts.AddHead(NewPart);
	
	PartCounter++;
	if (PartCounter % MotiveChangeThreshold == 0)
	{
		ChangeToNextMotive();
	}
}

void ATrunk::RemovePart()
{
	UTrunkCore* LastPart = GetTail();

	// Destroy all tail's children
	TArray<USceneComponent*> ChildrenComponents;
	LastPart->GetChildrenComponents(true, ChildrenComponents);
	while (ChildrenComponents.IsValidIndex(0))
	{
		ChildrenComponents[0]->DestroyComponent();
		ChildrenComponents.RemoveAt(0);
	}

	// Destroy Tail
	LastPart->DestroyComponent();

	// Remove Tail pointer
	TrunkParts.RemoveNode(LastPart);

	// Add a New Head
	NewPart();
}

UTrunkCore* ATrunk::GetHead() const
{
	return TrunkParts.GetHead() ? TrunkParts.GetHead()->GetValue() : nullptr;
}

UTrunkCore* ATrunk::GetTail() const
{
	return TrunkParts.GetTail() ? TrunkParts.GetTail()->GetValue() : nullptr;
}

void ATrunk::Turn_Implementation(const int Direction)
{
	const FString StringDirection = Direction == 1 ? TEXT("left") : TEXT("right");
	UE_LOG(LogTemp, Log, TEXT("Turning at direction: %s"), *StringDirection);
}