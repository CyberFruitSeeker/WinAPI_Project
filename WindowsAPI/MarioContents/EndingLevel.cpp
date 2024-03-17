#include "EndingLevel.h"
#include "EndingLogo.h"
#include <EngineCore/EngineCore.h>
#include <EnginePlatform/EngineInput.h>
#include <EnginePlatform/EngineSound.h>

EndingLevel::EndingLevel()
{
}

EndingLevel::~EndingLevel()
{
}

void EndingLevel::BeginPlay()
{
	EndingLogo* Ending = SpawnActor<EndingLogo>();

	



}

void EndingLevel::Tick(float _DeltaTime)
{

}
