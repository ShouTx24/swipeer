// Property of Kamil Bochenski. All right's reserved.

#include "TrunkMainPart.h"
#include "TrunkWall.h"
#include "Essence.h"

UTrunkMainPart::UTrunkMainPart()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTrunkMainPart::BeginPlay()
{
	Super::BeginPlay();
	
	//Set Static mesh if it exist.
	UStaticMesh* Mesh = Cast<ATrunk>(this->GetOwner())->GetStaticMesh(1);
	if (!Mesh) return;
	this->SetStaticMesh(Mesh);
	
	// Setup starting point.
	if (Cast<ATrunk>(GetOwner())->PartCounter < 5) return;

	//Create Instanced Static Mesh
	UTrunkWall* NewWall = NewObject<UTrunkWall>(this);
	NewWall->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
	NewWall->RegisterComponent();
	
	// How far we are
	int Parts = Cast<ATrunk>(GetOwner())->PartCounter;
	Parts = FMath::Log2(Parts / 10);
	
	// Setup starting point.
	if (Parts < 1) Parts = 1;
	// Ensure that game is always playable and you can not find part full of walls.
	else if (Parts > 5) Parts = 5;

	// Ensure that u cannot draw the same wall spot twice.
	TArray<int> possibles;
	for (int i{ 0 }; i < 8; i++) possibles.Add(i);
	Parts = FMath::RandRange(Parts, Parts + 2);
	
	// Place correct number of walls & essence.
	for (int i{ 0 }; i <= Parts; i++)
	{
		int id = FMath::RandRange(0, possibles.Num() - 1);
		int number = possibles[id];
		possibles.RemoveAt(id);
		if (i >= Parts)
		{
			UEssence* Essence = NewObject<UEssence>(this);
			Essence->AttachTo(this, FName(FString::FromInt(number)));
			Essence->RegisterComponent();
		}
		else NewWall->AddInstance(GetSocketTransform(FName(FString::FromInt(number))));
	}
}

void UTrunkMainPart::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

