#include "Troopa.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include <EngineCore/EngineResourcesManager.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include "Monster.h"
#include "Mario.h"
#include <EnginePlatform/EngineSound.h>

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
		Renderer->SetImage("Troopa_Right.png");
		//Renderer->ChangeAnimation("Move");
		Renderer->CreateAnimation("Move_Left", "Troopa_Left.png", 0, 1, 0.2f);
		Renderer->CreateAnimation("Move_Right", "Troopa_Right.png", 0, 1, 0.2f);
		//Renderer->SetScale({ 512,384 });
		Renderer->SetTransform({ {0,0},{585,445} });


		// 트루파 Dead 애니메이션이 작동되니?
		Renderer->CreateAnimation("Dead_Left", "Troopa_Left.png", 4, 4, 0.1f, true);
		Renderer->CreateAnimation("Dead_Right", "Troopa_Right.png", 4, 4, 0.1f, true);

	}

	// 트루파가 마리오랑 충돌하는가?
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Monster);
		BodyCollision->SetTransform({ { 0,-32 }, { 64, 64 } });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	DirState = EActorDir::Left;
	StateChange(TroopaState::Move);
}

void Troopa::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);

}


// 트루파는 png파일 자체에서 Left, Right가 있는데 이 CalMove 함수가 필요한가?
void Troopa::CalMove(float _DeltaTime)
{
	// 트루파가 땅에서 움직이니?

	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 30;
		break;;
	case EActorDir::Right:
		CheckPos.X += 30;
		break;
	default:
		break;
	}

	CheckPos.Y -= 20;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		switch (DirState)
		{
		case EActorDir::Left:
			DirState = EActorDir::Right;
			break;;
		case EActorDir::Right:
			DirState = EActorDir::Left;
			break;
		default:
			break;
		}

		DirCheck();
		MoveVector.X *= -1.0f;
	}

	AddActorLocation(MoveVector * _DeltaTime * MoveSpeed);

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


// 트루파에게 필요한 방향 체크(DirCheck)
void Troopa::DirCheck()
{
	std::string Name = GetAnimationName(CurAnimationName);
	Renderer->ChangeAnimation(Name, true, Renderer->GetCurAnimationFrame(), Renderer->GetCurAnimationTime());
}

// 이미지부터 좌우 방향이 있는 트루파에게 필요한 애니메이션 함수
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

	DeadSound = UEngineSound::SoundPlay("CrouchMoveAttack.wav");
	DeadSound.On();
}

void Troopa::DirChangeStart()
{
	
}



void Troopa::Move(float _DeltaTime)
{
	DirCheck();

	// 그래비티 & 무브 계산 기능은 움직임 함수 안에서 한번에 돌아가는 것이 맞다.
	CalGravity(_DeltaTime);
	CalMove(_DeltaTime);

}

void Troopa::Dead(float _DeltaTime)
{
	DirCheck();



}

void Troopa::DirChange(float _DeltaTime)
{
	DirCheck();


}


void Troopa::MarioJumpAttack()
{
	StateChange(TroopaState::Dead);


}



void Troopa::StateChange(TroopaState _State)
{
	if (State != _State)
	{
		switch (_State)
		{
		case TroopaState::Move:
			MoveStart();
			break;
		case TroopaState::Dead:
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
	switch (State)
	{
	case TroopaState::Move:
		Move(_DeltaTime);
		break;
	case TroopaState::Dead:
		Dead(_DeltaTime);
		break;
	default:
		break;
	}



}





