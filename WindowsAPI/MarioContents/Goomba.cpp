#include "Goomba.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <EngineCore/Actor.h>
#include <string>
#include <vector>
#include "Mario.h"

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
		Renderer->CreateAnimation("Move", "Goomba.png", 0, 1, 0.2f, true);
		Renderer->ChangeAnimation("Move");

		// 굼바 Dead 애니메이션이 작동되니?
		Renderer->CreateAnimation("Dead", "Goomba.png", 2, 2, 0.1f, true);


	}

	
	// 굼바가 마리오랑 충돌 하는가? => Jump Attack 으로 된다.
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
		/*CalGravity(_DeltaTime);
		CalMove(_DeltaTime);*/
		StateUpdate(_DeltaTime);
	}
	
}


// ================ 굼바에게 중력을 적용하고, 자동으로 움직이게 해보기 ===============
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

void Goomba::CalMove(float _DeltaTime)
{
	
	MoveVector * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	AddActorLocation(MoveVector);


}


void Goomba::MoveUpdate(float _DeltaTime)
{

	CalGravity(_DeltaTime);
}


// ========= 스테이트, 무브 업데이트 ==========

void Goomba::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
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

void Goomba::Move(float _DeltaTime)
{



	MoveUpdate(_DeltaTime);
}

void Goomba::Dead(float _DeltaTime)
{



	MoveUpdate(_DeltaTime);
}


void Goomba::StateChange(MonsterState _State)
{
	switch (_State)
	{
	case MonsterState::Move:
		MoveStart();
		break;
	case MonsterState::Dead:
		DeadStart();
		break;
	default:
		break;
	}
	

}

// 마리오의 점프어택과 굼바간의 상호작용이 일어났음을 알려주는 함수?
void Goomba::MarioJumpAttack()
{
	StateChange(MonsterState::Dead);

}

void Goomba::MoveStart()
{
	Renderer->ChangeAnimation(GetAnimation("Move"));


}

void Goomba::DeadStart()
{
	Renderer->ChangeAnimation(GetAnimation("Dead"));
	

}

void Goomba::DirCheck()
{


}

std::string Goomba::GetAnimation(std::string _Name)
{
	// 굼바가 움직이거나, 마리오의 점프킬로 죽어있니?
	
	//std::string DirChange;








	return std::string();
}



