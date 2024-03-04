#include "Goomba.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <EngineCore/Actor.h>
#include <string>
#include <vector>

Goomba::Goomba()
{
}

Goomba::~Goomba()
{
}

void Goomba::BeginPlay()
{
	AActor::BeginPlay();
	{
		SetName("Goomba");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Goomba.png");
		Renderer->SetScale({384, 384});
		Renderer->CreateAnimation("Move", "Goomba.png", 0, 1, 0.2f);
		Renderer->ChangeAnimation("Move");
	}

	
	// 굼바가 마리오랑 충돌 하는가?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ {0,-32},{64,64} });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	
	{

	}

	
}


void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	{
		CalGravity(_DeltaTime);

		CalMove(_DeltaTime);

	}
	
}


void Goomba::CalGravity(float _DeltaTime)
{



	
	GravityVector += GravityAccel * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}

	AddActorLocation(GravityVector);


}



// ================ 굼바를 땅에서 움직이게 해보기 ===============

void Goomba::CalMove(float _DeltaTime)
{
	
	MoveVector * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	
	AddActorLocation(MoveVector);

}

void Goomba::StateUpdate(float _DeltaTime)
{

}


void Goomba::StateChange(float _DeltaTime)
{

	switch (State)
	{
	case MonsterState::Idle:
		Idle(_DeltaTime);
		break;
	case MonsterState::Move:
		Move(_DeltaTime);
		break;
	case MonsterState::Dead:
		Dead(_DeltaTime);
		break;
	default:
		break;
	}


}

void Goomba::Idle(float _DeltaTime)
{
	if (true == Renderer->IsCurAnimationEnd())
	{
		int a = 0;
	}

}

void Goomba::Move(float _DeltaTime)
{

}

void Goomba::Dead(float _DeltaTime)
{

}



