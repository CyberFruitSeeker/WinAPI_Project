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
	//���� 0��°�� �׷���� �տ� �׷��ִ� �װ� �׷�����.
	{
		// ���⼭ ��ġ�� ���������ٰ� �̳༮��ġ�� 0,0�� ���� �ƴϴ�.
		ATitleLogo* Logo = SpawnActor<ATitleLogo>();
	}


}
void UTitleLevel::Tick(float _DeltaTime)
{
	ULevel::Tick(_DeltaTime);

	if (UEngineInput::IsDown('P'))
	{
		GEngine->ChangeLevel("Play");
	}

}
void UTitleLevel::LevelStart(ULevel* _PrevLevel)
{
	ULevel::LevelStart(_PrevLevel);
}
void UTitleLevel::LevelEnd(ULevel* _NextLevel)
{
	int a = 0;
}