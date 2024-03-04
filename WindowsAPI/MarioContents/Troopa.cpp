#include "Troopa.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include "Monster.h"
#include "Mario.h"

Troopa::Troopa()
{
}

Troopa::~Troopa()
{
}

void Troopa::BeginPlay()
{
	AActor::BeginPlay();
	{
		// 트루파 셋트랜스폼 크기 : 512, 384
		SetName("Troopa");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Troopa_Left.png");
		Renderer->CreateAnimation("Move", "Troopa_Left.png", 0, 1, 0.2f);
		Renderer->ChangeAnimation("Move");
		//Renderer->SetScale({ 512,384 });
		Renderer->SetTransform({ {0,0},{512,384} });
	}

	// 트루파가 마리오랑 충돌하는가?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ { 0,-32 }, { 64, 64 } });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

}

void Troopa::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	CalGravity(_DeltaTime);

	CalMove(_DeltaTime);

}


// 트루파는 png파일 자체에서 Left, Right가 있는데 이 CalMove 함수가 필요한가?
void Troopa::CalMove(float _DeltaTime)
{
	// 트루파가 땅에서 움직이니?
	MoveVector * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);

	AddActorLocation(MoveVector);

}

void Troopa::CalGravity(float _DeltaTime)
{

	{
		GravityVector += GravityAcc * _DeltaTime;
		Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
		if (Color == Color8Bit(255, 0, 255, 0))
		{
			GravityVector = FVector::Zero;
		}

		AddActorLocation(GravityVector);
	}

}

void Troopa::MoveStart()
{

}

void Troopa::DeadStart()
{

}

void Troopa::Move(float _DeltaTime)
{

}

void Troopa::Dead(float _DeltaTime)
{

}

void Troopa::MarioJumpAttack()
{
	StateChange(MonsterState::Dead);

}


void Troopa::StateChange(MonsterState _State)
{
}

void Troopa::StateUpdate(float _DeltaTime)
{
}


// 이미지부터 좌우 방향이 있는 트루파에게 필요한 애니메이션 함수
std::string Troopa::GetAnimationName(std::string _Name)
{



	return std::string();
}



