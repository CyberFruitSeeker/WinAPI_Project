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
		// GetAnimation�� ���� �����ϱ� StateChange�� �ٷ� �ẻ��.
		StateChange(GoombaState::Move);


		// ���� Dead �ִϸ��̼��� �۵��Ǵ�?
		Renderer->CreateAnimation("Dead", "Goomba.png", 2, 2, 0.1f, true);


	}

	
	// ���ٰ� �������� �浹 �ϴ°�? => Jump Attack ���� �ȴ�.
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ {0,-32},{64,64} });
		BodyCollision->SetColType(ECollisionType::Rect);
	}


}


void Goomba::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);
	
	StateUpdate(_DeltaTime);
	
	
}


// ================ ���ٿ��� �߷��� �����ϰ�, �ڵ����� �����̰� �غ��� ===============
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
	
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 30;
		break;
	case EActorDir::Right:
		CheckPos.X += 30;
		break;
	default:
		break;
	}
	CheckPos.Y -= 20;

	//MoveVector* _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector.X *= -1.0f;
	}

	AddActorLocation(MoveVector * _DeltaTime * MoveSpeed);

	

	
}




// ========= ������Ʈ, ���� ������Ʈ ==========
void Goomba::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case GoombaState::Move:
		Move(_DeltaTime);
		break;
	case GoombaState::Dead:
		Dead(_DeltaTime);
		break;
	default:
		break;
	}

	CalMove(_DeltaTime);
	CalGravity(_DeltaTime);
}

void Goomba::Move(float _DeltaTime)
{
	{
		StateChange(GoombaState::Move);
		return;
	}


	
}

void Goomba::Dead(float _DeltaTime)
{
	int a = 0;

	
}


void Goomba::StateChange(GoombaState _State)
{
	switch (_State)
	{
	case GoombaState::Move:
		MoveStart();
		break;
	case GoombaState::Dead:
		DeadStart();
		break;
	default:
		break;
	}
	State = _State;

}

void Goomba::MoveStart()
{
	Renderer->ChangeAnimation("Move");


}

void Goomba::DeadStart()
{
	MoveVector = FVector::Zero;
	Renderer->ChangeAnimation("Dead");
	Destroy(1.0f);
}


// �������� ���������� �������� ��ȣ�ۿ��� ����Ű�� �ϴ� �Լ�
void Goomba::MarioJumpAttack()
{
	StateChange(GoombaState::Dead);

}


