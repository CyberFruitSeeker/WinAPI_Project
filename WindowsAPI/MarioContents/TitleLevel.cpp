#include "TitleLevel.h"
#include "TitleLogo.h"
#include "EngineCore\EngineCore.h"

UTitleLevel::UTitleLevel()
{
}

UTitleLevel::~UTitleLevel()
{
}

void UTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		// ���⼭ ��ġ�� ���������ٰ� �̳༮��ġ�� 0,0�ΰ� �ƴ���
		ATitleLogo* Logo = SpawnActor<ATitleLogo>();
	}


}
void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (EngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("Play");
	}

}
void UTitleLevel::LevelStart(ULevel* _Level)
{
	int a = 0;
}
void UTitleLevel::LevelEnd(ULevel* _Level)
{
	int a = 0;
}