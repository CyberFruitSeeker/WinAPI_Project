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
	//맵을 0번째에 그려줘야 앞에 그려주는 그게 그려진다.
	{
		// 여기서 위치가 안정해졌다고 이녀석위치가 0,0인 것은 아니다.
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