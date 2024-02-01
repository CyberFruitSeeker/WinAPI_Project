#include "TestPlayer.h"
#include <EnginePlatform\EngineInput.h>

ATestPlayer::ATestPlayer()
{
}

ATestPlayer::~ATestPlayer()
{
}

void ATestPlayer::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer();
	Renderer->SetImage("Player_Right.png");
	Renderer->SetTransform({ {0,0}, {100, 100} });
	Renderer->SetImageCuttingTransform({ {64,64}, {32, 32} });
	Renderer->CreateAnimation("Idle", "Player_Right.png", 0, 12, 0.5f, true);
	Renderer->CreateAnimation("Attack", "Player_Right.png", 26, 32, 0.5f, true);
	Renderer->CreateAnimation("Attack2", "Player_Right.png", 52, 58, 0.5f, true);
	Renderer->ChangeAnimation("Idle");

}

void ATestPlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	if (EngineInput::IsDown('Q'))
	{
		Renderer->ChangeAnimation("Attack2");
	}

	//// 어떻게 편하게 쓸까?
	//// 테스트 코드
	//AnimationTime -= _DeltaTime;

	//if (0 >= AnimationTime)
	//{
	//	AnimationFrame++;
	//	AnimationTime = 1.0f;
	//}

	//Renderer->SetImageIndex(AnimationFrame);
}