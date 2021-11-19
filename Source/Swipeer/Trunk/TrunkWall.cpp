// Property of Kamil Bochenski. All right's reserved.

#include "TrunkWall.h"

void UTrunkWall::BeginPlay()
{
	Super::BeginPlay();
	SetStaticMesh(Cast<ATrunk>(GetOwner())->GetStaticMesh(2));
}