#include "ContentsCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayLevel.h"

ContentsCore::ContentsCore()
	: EngineCore()
{
}

ContentsCore::~ContentsCore()
{
}

// 게임시작
void ContentsCore::BeginPlay()
{
	SetFrame(60);

	// 이곳에서 필요한 모든 리소스를 싸그리 로드하는 방법 <= 추천하지 않는다.
	// 리소스 낭비를 하겠다는것 사용하지도 않을 리소스를 미리다 로드해 놓겠다.
	// 보통 엔진이라면 내가 현재 사용하는 리소스만 깔끔하게 로드하는 방법을 마련해 놔야하면서
	// 동시에 그걸 사용자가 눈치채지 못하게 해야 한다.

	// "Title Level" + "을 만들다가 에러가 났습니다";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void ContentsCore::Tick(float _DeltaTime)
{
	// 플레이어 움직여야 한다.
}

void ContentsCore::End()
{
}