#include "TestPlayer.h"
#include <EnginePlatform\EngineInput.h>
#include <EngineBase\EngineDebug.h>
#include "ContentsHelper.h"

ATestPlayer::ATestPlayer()
{
}

ATestPlayer::~ATestPlayer()
{
}

void ATestPlayer::BeginPlay()
{
	AActor::BeginPlay();

	Renderer = CreateImageRenderer(MarioRenderOrder::Player);
	Renderer->SetImage("TestPlayer_Right.png");
	Renderer->SetTransform({ {0,0}, {256, 256} });
	Renderer->CreateAnimation("Small_Idle_Right", "TestPlayer_Right.png", 0, 0, 0.5f, true);
	Renderer->ChangeAnimation("Small_Idle_Right");
}

void ATestPlayer::GravityCheck(float _DeltaTime)
{
	Color8Bit Color = UContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY());
	if (Color != Color8Bit(255, 0, 255, 0))
	{
		AddActorLocation(FVector::Down * _DeltaTime * Gravity);
	}
}

void ATestPlayer::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case PlayState::Idle:
		Idle(_DeltaTime);
		break;
	case PlayState::Move:
		Move(_DeltaTime);
		break;
	case PlayState::Jump:
		Jump(_DeltaTime);
		break;
	default:
		break;
	}


}

void ATestPlayer::Idle(float _DeltaTime)
{
	GravityCheck(_DeltaTime);
}
void ATestPlayer::Jump(float _DeltaTime)
{

}
void ATestPlayer::Move(float _DeltaTime)
{

}


void ATestPlayer::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);
}
