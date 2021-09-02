#include "TrunkWall.h"
#include "TrunkMainPart.h"

void UTrunkWall::BeginPlay()
{
	Super::BeginPlay();
	SetStaticMesh(Cast<ATrunk>(GetOwner())->GetStaticMesh(2));
}