#include "TestTitleLevel.h"
#include "TestTitleLogo.h"
#include "EngineCore\EngineCore.h"

UTestTitleLevel::UTestTitleLevel()
{
}

UTestTitleLevel::~UTestTitleLevel()
{
}

void UTestTitleLevel::BeginPlay()
{
	ULevel::BeginPlay();

	{
		// ���⼭ ��ġ�� ���������ٰ� �̳༮��ġ�� 0,0�ΰ� �ƴ���
		ATestTitleLogo* Logo = SpawnActor<ATestTitleLogo>();
	}


}
void UTestTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (EngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("Play");
	}

}
void UTestTitleLevel::LevelStart(ULevel* _Level)
{
	int a = 0;
}
void UTestTitleLevel::LevelEnd(ULevel* _Level)
{
	int a = 0;
}