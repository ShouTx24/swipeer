// Property of Kamil Bochenski. All right's reserved.

#include "TrunkCore.h"

#include "Essence.h"
#include "Trunk.h"

void UTrunkCore::BeginPlay()
{
	Super::BeginPlay();
	
	ATrunk* Trunk = GetOwner<ATrunk>();

	int Parts = Trunk->PartCounter;
	
	// Setup starting point.
	if (Parts < 5)
	{
		return;
	}
	
	// How far we are
	Parts = FMath::LogX(3,Parts / 10);
	
	// Ensure that there is at least one valid part.
	if (Parts < 1)
	{
		Parts = 1;
	}
	// Ensure that game is always playable and you can not find part full of walls.
	else if (Parts > 5)
	{
		Parts = 5;
	}

	// Ensure that u cannot draw the same wall spot twice.
	TArray<int> Possibles;
	for (int i = 0; i < 8; i++)
	{
		Possibles.Add(i);
	}
	Parts = FMath::RandRange(Parts, Parts + 2);
	
	// Place correct number of walls & essence.
	FMotive Motive = Trunk->GetActiveMotive();
	
	for (int i = 0; i <= Parts; i++)
	{
		const int ID = FMath::RandRange(0, Possibles.Num() - 1);
		const int Number = Possibles[ID];
		Possibles.RemoveAt(ID);
		if (i >= Parts)
		{
			UEssence* Essence = NewObject<UEssence>(this);
			Essence->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform, FName(FString::FromInt(Number)));
			Essence->RegisterComponent();
		}
		else
		{
			// Add Wall
			UStaticMeshComponent* NewWall = NewObject<UStaticMeshComponent>(this);
			NewWall->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform, FName(FString::FromInt(Number)));
			NewWall->SetStaticMesh(Motive.Walls[FMath::RandRange(0, Motive.Walls.Num() - 1)]);
			NewWall->RegisterComponent();
		}
	}
}
