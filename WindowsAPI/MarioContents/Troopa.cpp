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
		// Ʈ���� ��Ʈ������ ũ�� : 512, 384
		SetName("Troopa");
		Renderer = CreateImageRenderer(MarioRenderOrder::Monster);
		Renderer->SetImage("Troopa_Left.png");
		Renderer->CreateAnimation("Move_Left", "Troopa_Left.png", 0, 1, 0.2f);
		Renderer->CreateAnimation("Move_Right", "Troopa_Right.png", 0, 1, 0.2f);
		//Renderer->ChangeAnimation("Move");
		//Renderer->SetScale({ 512,384 });
		Renderer->SetTransform({ {0,0},{512,384} });


		// Ʈ���� Dead �ִϸ��̼��� �۵��Ǵ�?
		Renderer->CreateAnimation("Dead_Left", "Troopa_Left.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Dead_Right", "Troopa_Right.png", 4, 4, 0.1f, true);

	}

	// Ʈ���İ� �������� �浹�ϴ°�?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ { 0,-32 }, { 64, 64 } });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

}

void Troopa::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


// Ʈ���Ĵ� png���� ��ü���� Left, Right�� �ִµ� �� CalMove �Լ��� �ʿ��Ѱ�?
void Troopa::CalMove(float _DeltaTime)
{
	// Ʈ���İ� ������ �����̴�?
	
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 3;
		break;;
	case EActorDir::Right:
		CheckPos.X += 3;
		break;
	default:
		break;
	}
	
	CheckPos.Y -= 20;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}

	//MoveVector * _DeltaTime;
	AddActorLocation(MoveVector);
	
	
}

void Troopa::CalGravity(float _DeltaTime)
{

	{
		GravityVector += GravityAccel * _DeltaTime;
		Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
		if (Color == Color8Bit(255, 0, 255, 0))
		{
			GravityVector = FVector::Zero;
		}

		AddActorLocation(GravityVector);
	}

}


// Ʈ���Ŀ��� �ʿ��� ���� üũ(DirCheck)
void Troopa::DirCheck()
{
	EActorDir Dir = DirState;
	Dir = EActorDir::Left;
	Dir = EActorDir::Right;

	if (Dir != DirState)
	{
		DirState = Dir;
		std::string Name = GetAnimationName(CurAnimationName);
		Renderer->ChangeAnimation(Name, true, Renderer->GetCurAnimationFrame(), Renderer->GetCurAnimationTime());

	}


}

// �̹������� �¿� ������ �ִ� Ʈ���Ŀ��� �ʿ��� �ִϸ��̼� �Լ�
std::string Troopa::GetAnimationName(std::string _Name)
{
	std::string DirName = "";

	switch (DirState)
	{
	case EActorDir::Left:
		DirName = "_Left";
		break;
	case EActorDir::Right:
		DirName = "_Right";
		break;
	default:
		break;
	}

	CurAnimationName = _Name;

	return _Name + DirName;
}



void Troopa::MoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Move"));
	DirCheck();
}

void Troopa::DeadStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Dead"));
	DirCheck();
	

	
}

void Troopa::Move(float _DeltaTime)
{
	DirCheck();

	{
		StateChange(MonsterState::Move);
		return;
	}

	{
		(FVector::Left * _DeltaTime);
	}

	{
		(FVector::Right * _DeltaTime);
	}


}

void Troopa::Dead(float _DeltaTime)
{
	DirCheck();

	{
		StateChange(MonsterState::Dead);
		return;
	}


}

void Troopa::MarioJumpAttack()
{
	StateChange(MonsterState::Dead);


}



void Troopa::StateChange(MonsterState _State)
{
	if (State != _State)
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

	State = _State;
}

void Troopa::StateUpdate(float _DeltaTime)
{
	CalGravity(_DeltaTime);
	CalMove(_DeltaTime);

}





