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

	//{
	//	EndingBGM = UEngineSound::SoundPlay("StageClear.wav");
	//	EndingBGM.On();

	//}



}

void EndingLevel::Tick(float _DeltaTime)
{

}
