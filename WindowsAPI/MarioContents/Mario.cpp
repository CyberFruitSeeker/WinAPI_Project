#include "Mario.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include <string>
#include <vector>
#include <EngineCore/Collision.h>
#include "Mushroom.h"


Mario* Mario::ItsMeMario = nullptr;

Mario* Mario::GetItsMeMario()
{
	return ItsMeMario;
}

Mario::Mario()
{
}

Mario::~Mario()
{
}

void Mario::BeginPlay()
{
	AActor::BeginPlay();
	//ItsMeMario = this;

	// Small Mario �ִϸ��̼�
	{
		Renderer = CreateImageRenderer(MarioRenderOrder::Player);
		SetName("SmallMario");
		Renderer->SetImage("Mario_Right.png");
		Renderer->SetTransform({ {0,0}, {256, 256} });
		Renderer->CreateAnimation("Idle_Right_Small", "Mario_Right.png", 0, 0, 0.30f, true);
		Renderer->CreateAnimation("Idle_Left_Small", "Mario_Left.png", 0, 0, 0.30f, true);

		Renderer->CreateAnimation("Run_Right_Small", "Mario_Right.png", { 1, 2, 3 }, 0.1f, true);
		Renderer->CreateAnimation("Run_Left_Small", "Mario_Left.png", { 1, 2, 3 }, 0.1f, true);

		Renderer->CreateAnimation("Jump_Right_Small", "Mario_Right.png", 5, 5, 0.1f, true);
		Renderer->CreateAnimation("Jump_Left_Small", "Mario_Left.png", 5, 5, 0.1f, true);






		// Renderer->ChangeAnimation("Idle_Right");
	}

	// Small Mario �϶� Collision
	{
		BodyCollision = CreateCollision(MarioCollisionOrder::Player);
		BodyCollision->SetTransform({ {0,-32},{64,64} });
		BodyCollision->SetColType(ECollisionType::Rect);
	}

	// Big Mario �϶� Coliision => Small Mario ���� y�����θ� ��� �ϸ� �ȴ�.
	// �׸��� �� �������� Collision�� Block�� ���Ľ�ų �� �ִ�.
	{

	}

	// ���ٿ� Ʈ���ĸ� Jump Kill �ϱ� ���� ������ DownCollision
	// ������ ��尡 �޶����� x�� ������ ������ �����ϱ� �������� �����
	{
		DownCollision = CreateCollision(MarioCollisionOrder::Player);
		DownCollision->SetTransform({ {0,0},{64,15} });
		DownCollision->SetColType(ECollisionType::Rect);
	}

	{
		
	}


	MarioModeChange(MarioMode::SmallMario);
	StateChange(MarioState::Idle);
}


// StateUpdate �ȿ� ����ִ� FSM�� Tick���� ���ư���.
void Mario::Tick(float _DeltaTime)
{
	AActor::Tick(_DeltaTime);

	StateUpdate(_DeltaTime);
}


// ========== ������ ��� ===========

// �������� ��尡 �ٲ��.
// ������ �⺻(����)���´� SmallMario �̴�.
void Mario::MarioModeChange(MarioMode _Mode)
{

	switch (Mode)
	{
	case MarioMode::SmallMario:
		SmallMario();
		break;
	case MarioMode::BigMario:
		BigMario();
		break;
	case MarioMode::FireMario:
		FireMario();
		break;
	default:
		break;
	}

	StateChange(MarioState::Idle);
}

void Mario::SmallMario()
{

}

void Mario::BigMario()
{



}

void Mario::FireMario()
{

}








// ====== ī�޶� ������ ��ɵ� ======

void Mario::MoveLastCameraPos(float _DeltaTime)
{
	// ī�޶�� x�����θ� �����̰� �غ���.
	GetWorld()->AddCameraPos(MoveVector * _DeltaTime);
	AddActorLocation(LastMoveVector * _DeltaTime);

	// 
	// �ʿ��� ����(0, 0) ����(���̳ʽ�)�� �������� �ϴ� �ڵ尡
	// Map Ŭ���� Ȥ�� PlayLevel�� �����Ǿ��ִ�.
	// ������ �浹 ��� ������ �켱 �ּ�ó��
}

// �������� �����ӿ� ���� ī�޶� ��ġ ����
void Mario::MoveCameraMarioPos(float _DeltaTime)
{
	FVector CurCamPos = GetWorld()->GetCameraPos();
	FVector MarioPos = GetActorLocation();
	float SceneCenter = GEngine->MainWindow.GetWindowScale().hX();
	if (MarioPos.X > SceneCenter + CurCamPos.X)
	{
		GetWorld()->SetCameraPos({ MarioPos.X - SceneCenter,CurCamPos.Y });
	}
}


/// ============== �������� �̵����� Ű�Է°� ���õ� ��ɵ� ==============

void Mario::AddMoveVector(const FVector& _DeltaTime)
{
	MoveVector += _DeltaTime * MoveAccel;
}

void Mario::CalMoveVector(float _DeltaTime)
{
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 35;
		break;
	case EActorDir::Right:
		CheckPos.X += 35;
		break;
	default:
		break;
	}
	CheckPos.Y -= 35;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(CheckPos.iX(), CheckPos.iY(), Color8Bit::MagentaA);

	if (Color == Color8Bit(255, 0, 255, 0))
	{
		MoveVector = FVector::Zero;
	}

	if (true == UEngineInput::IsFree(VK_LEFT) && true == UEngineInput::IsFree(VK_RIGHT))
	{
		if (0.001 <= MoveVector.Size2D())
		{
			MoveVector += (-MoveVector.Normalize2DReturn()) * _DeltaTime * MoveAccel;
		}
		else
		{
			MoveVector = float4::Zero;
		}
	}

	if (MoveMaxSpeed <= MoveVector.Size2D())
	{
		MoveVector = MoveVector.Normalize2DReturn() * MoveMaxSpeed;
	}
}


// ====== Ű �Է����� ���� �������� �����Ӱ� �ִϸ��̼� =======

void Mario::Idle(float _DeltaTime)
{
	if (true == Renderer->IsCurAnimationEnd())
	{
		int a = 0;
	}

	// ���ʵ�, �����ʵ� �Ȱ��� �ְ�,
	// ���⼭�� ������ �������� ��� ���� �Ű澲�� �ȴ�.
	if (true == UEngineInput::IsDown('1'))
	{
		StateChange(MarioState::FreeMove);
		return;
	}

	if (true == UEngineInput::IsDown('2'))
	{
		StateChange(MarioState::CameraFreeMove);
		return;
	}


	if (
		true == UEngineInput::IsPress(VK_LEFT) ||
		true == UEngineInput::IsPress(VK_RIGHT)
		)
	{
		StateChange(MarioState::Run);
		return;
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		StateChange(MarioState::Jump);
		return;
	}

	MoveUpdate(_DeltaTime);

}

void Mario::Jump(float _DeltaTime)
{
	// EnumType _Order, std::vector<UCollision*>& _Result;

	// ����Ҷ��� ����ų�� �ߵ��ϸ� �ȵǴϱ�, �̸� ���� ���ǹ��� �����.
	if (IsJumpDown())
	{
		std::vector<UCollision*> _Result;
		if (true == DownCollision->CollisionCheck(MarioCollisionOrder::Monster, _Result))
		{
			for (size_t i = 0; i < _Result.size(); i++)
			{
				AMonsterSetting* Monster = dynamic_cast<AMonsterSetting*>(_Result[i]->GetOwner());
				Monster->MarioJumpAttack();

				// _Result[i]->GetOwner();/*->Destroy();*/
			}
		}

	}


	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	MoveUpdate(_DeltaTime);

	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		JumpVector = FVector::Zero;
		StateChange(MarioState::Idle);
		return;
	}
}


void Mario::Run(float _DeltaTime)
{
	DirCheck();

	if (true == UEngineInput::IsFree(VK_LEFT) && UEngineInput::IsFree(VK_RIGHT))
	{
		StateChange(MarioState::Idle);
		return;
	}

	if (UEngineInput::IsPress(VK_LEFT))
	{
		AddMoveVector(FVector::Left * _DeltaTime);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		AddMoveVector(FVector::Right * _DeltaTime);
	}

	if (true == UEngineInput::IsDown(VK_SPACE))
	{
		StateChange(MarioState::Jump);
		return;
	}


	MoveUpdate(_DeltaTime);
}

void Mario::IdleStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Idle"));
	DirCheck();
}

void Mario::RunStart()
{
	Renderer->ChangeAnimation(GetAnimationName("Run"));
	DirCheck();
}

void Mario::JumpStart()
{
	JumpVector = JumpPower;
	Renderer->ChangeAnimation(GetAnimationName("Jump"));
	DirCheck();
}


void Mario::FreeMove(float _DeltaTime)
{
	FVector FreeMove = FVector::Zero;

	if (UEngineInput::IsPress(VK_LEFT))
	{
		FreeMove += FVector::Left * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		FreeMove += FVector::Right * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		FreeMove += FVector::Up * _DeltaTime * FreeMoveSpeed;
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		FreeMove += FVector::Down * _DeltaTime * FreeMoveSpeed;
	}

	AddActorLocation(FreeMove * _DeltaTime);
	GetWorld()->AddCameraPos(FreeMove * _DeltaTime);

	if (UEngineInput::IsDown('1'))
	{
		StateChange(MarioState::Idle);
	}
}


// ====== �������� �߷�, ���ӵ� ���� ������ ��� =========

void Mario::CalJumpVector(float _DeltaTime)
{

}

void Mario::CalGravityVector(float _DeltaTime)
{
	GravityVector += GravityAccel * _DeltaTime;
	Color8Bit Color = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX(), GetActorLocation().iY(), Color8Bit::MagentaA);
	if (Color == Color8Bit(255, 0, 255, 0))
	{
		GravityVector = FVector::Zero;
	}
}


void Mario::CalLastMoveVector(float _DeltaTime)
{
	// ���� ���͵��� ���η� ���� �ʱ�ȭ ������� �Ѵ�.
	LastMoveVector = FVector::Zero;
	LastMoveVector = LastMoveVector + MoveVector;
	LastMoveVector = LastMoveVector + JumpVector;
	LastMoveVector = LastMoveVector + GravityVector;
}


void Mario::MoveUpdate(float _DeltaTime)
{
	// �̵��� �ϴٰ� �������� ���̳� ������Ʈ�� ó���� �� �ִ� ���� �����ϱ� ���� ��
	CalMoveVector(_DeltaTime);
	CalGravityVector(_DeltaTime);
	CalLastMoveVector(_DeltaTime);
	MoveLastCameraPos(_DeltaTime);
}




/// ========= ������ �̹��� ��, �ִϸ��̼�, ������Ʈ =========

void Mario::DirCheck()
{
	EActorDir Dir = DirState;
	if (UEngineInput::IsPress(VK_LEFT))
	{
		Dir = EActorDir::Left;
	}
	if (UEngineInput::IsPress(VK_RIGHT))
	{
		Dir = EActorDir::Right;
	}

	if (Dir != DirState)
	{
		DirState = Dir;
		std::string Name = GetAnimationName(CurAnimationName);
		// Renderer->ChangeAnimation(Name, true);
		Renderer->ChangeAnimation(Name, true, Renderer->GetCurAnimationFrame(), Renderer->GetCurAnimationTime());
	}
}


std::string Mario::GetAnimationName(std::string _Name)
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

	std::string ModeName = "";

	switch (Mode)
	{
	case MarioMode::SmallMario:
		ModeName = "_Small";
		break;
	case MarioMode::BigMario:
		ModeName = "_Big";
		break;
	default:
		break;
	}


	CurAnimationName = _Name;

	return _Name + DirName + ModeName;
}

void Mario::StateChange(MarioState _State)
{
	// �������� ���°� ���ϴ� �Ϳ� �����ϴ� �Լ�
	if (State != _State)
	{
		switch (_State)
		{
		case MarioState::Idle:
			IdleStart();
			break;
		case MarioState::Run:
			RunStart();
			break;
		case MarioState::Jump:
			JumpStart();
			break;
		default:
			break;
		}
	}

	State = _State;
}



void Mario::StateUpdate(float _DeltaTime)
{
	switch (State)
	{
	case MarioState::CameraFreeMove:
		CameraFreeMove(_DeltaTime);
		break;
	case MarioState::FreeMove:
		FreeMove(_DeltaTime);
		break;
	case MarioState::Idle:
		Idle(_DeltaTime);
		break;
	case MarioState::Run:
		Run(_DeltaTime);
		break;
	case MarioState::Jump:
		Jump(_DeltaTime);
		break;
	default:
		break;
	}

}

void Mario::CameraFreeMove(float _DeltaTime)
{
	if (UEngineInput::IsPress(VK_LEFT))
	{
		GetWorld()->AddCameraPos(FVector::Left * _DeltaTime * 500.0f);
		//AddActorLocation(FVector::Left * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_RIGHT))
	{
		//                             2        *  �ð�      * 500
		GetWorld()->AddCameraPos(FVector::Right * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_UP))
	{
		GetWorld()->AddCameraPos(FVector::Up * _DeltaTime * 500.0f);
		//AddActorLocation(FVector::Up * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsPress(VK_DOWN))
	{
		GetWorld()->AddCameraPos(FVector::Down * _DeltaTime * 500.0f);
		//AddActorLocation(FVector::Down * _DeltaTime * 500.0f);
	}

	if (UEngineInput::IsDown('2'))
	{
		StateChange(MarioState::Idle);
	}
}




