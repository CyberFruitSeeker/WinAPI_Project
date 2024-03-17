#include "Mario.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase/EngineDebug.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include <string>
#include <vector>
#include <EngineCore/Collision.h>
#include "Mushroom.h"
#include "BlockCommonClass.h"
#include "EngineCore/EngineCore.h"
#include "MarioMap.h"
#include "PlayLevel.h"
#include <EngineCore/Level.h>
#include "Flag.h"

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
	
	/*BGMPlay = UEngineSound::SoundPlay("Level1.mp3");
	BGMPlay.Loop();*/


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

		Renderer->CreateAnimation("FlagStop_Right_Small", "Mario_Right.png", 8, 8, 0.1f, true);
		Renderer->CreateAnimation("FlagStop_Left_Small", "Mario_Left.png", 8, 8, 0.1f, true);

		Renderer->CreateAnimation("FlagAutoMove_Right_Small", "Mario_Right.png", { 1, 2, 3 }, 0.1f, true);
		Renderer->CreateAnimation("FlagAutoMove_Left_Small", "Mario_Left.png", { 1, 2, 3 }, 0.1f, true);

		//Renderer = CreateImageRenderer(MarioMode::BigMario);
		SetName("BigMario");
		Renderer->CreateAnimation("Idle_Right_Big", "Mario_Right.png", 9, 9, 0.3f, true);
		Renderer->CreateAnimation("Idle_Left_Big", "Mario_Left.png", 9, 9, 0.3f, true);

		Renderer->CreateAnimation("Run_Right_Big", "Mario_Right.png", { 10, 11, 12 }, 0.1f, true);
		Renderer->CreateAnimation("Run_Left_Big", "Mario_Left.png", { 10, 11, 12 }, 0.1f, true);

		Renderer->CreateAnimation("Jump_Right_Big", "Mario_Right.png", 14, 14, 0.1f, true);
		Renderer->CreateAnimation("Jump_Left_Big", "Mario_Left.png", 14, 14, 0.1f, true);

		Renderer->CreateAnimation("FlagStop_Right_Big", "Mario_Right.png", 17, 17, 0.1f, true);
		Renderer->CreateAnimation("FlagStop_Left_Big", "Mario_Left.png", 17, 17, 0.1f, true);

		Renderer->CreateAnimation("FlagAutoMove_Right_Big", "Mario_Right.png", { 10, 11, 12 }, 0.1f, true);
		Renderer->CreateAnimation("FlagAutoMove_Left_Big", "Mario_Left.png", { 10, 11, 12 }, 0.1f, true);


		// Renderer->ChangeAnimation("Idle_Right");
	}

	// Small & Big Mario �϶� Collision ��ȭ�� �̰� BeginPlay�� �ƴ϶�
	// �Ʒ��� �ִ� FSM���� �����ϰ� �Ѵ�.


	// ���ٿ� Ʈ���ĸ� Jump Kill �ϱ� ���� ������ DownCollision
	// ������ ��尡 �޶����� x�� ������ ������ ���ٴ� �Ϳ� ����
	{
		DownCollision = CreateCollision(MarioCollisionOrder::Player);
		DownCollision->SetTransform({ {0,0},{64,15} });
		DownCollision->SetColType(ECollisionType::Rect);
	}

	LeftMagentaShield = CreateCollision(MarioCollisionOrder::Player);
	LeftMagentaShield->SetColType(ECollisionType::Rect);
	RightMagentaShield = CreateCollision(MarioCollisionOrder::Player);
	RightMagentaShield->SetColType(ECollisionType::Rect);
	BottomMagentaShield = CreateCollision(MarioCollisionOrder::Player);
	BottomMagentaShield->SetColType(ECollisionType::Rect);

	BodyCollision = CreateCollision(MarioCollisionOrder::Player);
	BodyCollision->SetColType(ECollisionType::Rect);



	MarioModeChange(MarioMode::SmallMario);
	StateChange(MarioState::Idle);
}


// StateUpdate �ȿ� ����ִ� FSM�� Tick���� ���ư���.
void Mario::Tick(float _DeltaTime)
{

	//AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);
	MoveCameraMarioPos(_DeltaTime);
}

void Mario::BGMSoundControl()
{

}

// �������� ������ ���̴� ���� ����
void Mario::MarioMagentaShiled(float _DeltaTime)
{



}



void Mario::MarioFlagInteractive(float _DeltaTime)
{
	MarioFlagCollision(_DeltaTime);
	//MarioFlagAnimation(_DeltaTime);
}

// �������� Flag�� Collision ��ȣ�ۿ��� �߻��ߴٴ� ���� �˷��ش�.
void Mario::MarioFlagCollision(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == BodyCollision->CollisionCheck(MarioCollisionOrder::FlagUp, Result))
	{
		StateChange(MarioState::FlagStop);
	}

}


// ==================== ������ ��� ü���� =====================

// �������� ��尡 �ٲ��.(�ø����� y�� ũ�⵵ �þ��.)
// ������ �⺻(����)���´� SmallMario �̴�.
void Mario::MarioModeChange(MarioMode _MarioMode)
{
	Mode = _MarioMode;

	switch (_MarioMode)
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


	switch (_MarioMode)
	{
	case MarioMode::SmallMario:
		BodyCollision->SetTransform({ {0,-32},{50,64} });
		LeftMagentaShield->SetTransform({ {-30,-20},{15,64} });
		RightMagentaShield->SetTransform({ {30,-20},{15,64} });
		BottomMagentaShield->SetTransform({ {0,4},{64,15} });
		break;
	case MarioMode::BigMario:
		BodyCollision->SetTransform({ {0,-64},{50,128} });
		LeftMagentaShield->SetTransform({ {-30,-60},{15,128} });
		RightMagentaShield->SetTransform({ {30,-60},{15,128} });
		BottomMagentaShield->SetTransform({ {0,4},{64,15} });
		break;
	case MarioMode::FireMario:
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
	//Renderer->CreateAnimation("Idle_Right_Big", "Mario_Right.png", { 0, 19, 9 }, 0.3f, true);
	//Renderer->CreateAnimation("Idle_Left_Big", "Mario_Left.png", { 0, 19, 9 }, 0.3f, true);

	Renderer->ChangeAnimation(GetAnimationName("Idle"));

}

void Mario::FireMario()
{

}



// ====== ī�޶� ������ ��ɵ� ======

// ���������� FVector�� �����ϰ� �ϰ�, ī�޶� �����̰� ���ش�.
void Mario::MarioVectorMoveCameraPos(float _DeltaTime)
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
	GetWorld()->SetCameraPos({ MarioPos.X - 300.0f,CurCamPos.Y });

	FVector CameraPos = GetWorld()->GetCameraPos();
	if (CameraPos.X < 0.0f)
	{
		CameraPos.X = 0.0f;
		GetWorld()->SetCameraPos(CameraPos);
	}

	if (CameraPos.X > 12445.0f)
	{
		CameraPos.X = 12445.0f;
		GetWorld()->SetCameraPos(CameraPos);
	}

}


/// ============== �������� �̵����� Ű�Է°� ���õ� ��ɵ� ==============

void Mario::AddMoveVector(const FVector& _Value)
{
	MoveVector += _Value * MoveAccel;
}

void Mario::CalMoveVector(float _DeltaTime)
{
	FVector CheckPos = GetActorLocation();
	switch (DirState)
	{
	case EActorDir::Left:
		CheckPos.X -= 45;
		break;
	case EActorDir::Right:
		CheckPos.X += 45;
		break;
	default:
		break;
	}
	CheckPos.Y -= 50;
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

// �������� �⺻ ���¿��� ���� ���۵��� �ϱ� ���� ���ǹ����� ��� �Լ�
void Mario::Idle(float _DeltaTime)
{
	if (true == Renderer->IsCurAnimationEnd())
	{
		int a = 0;
	}

	// �������� �ϰ��� �ϴ� ���ۿ� ���� Ű�Է�
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

	// �������� �����Ҷ��� ��߰� ��ȣ�ۿ� �ϱ� ���� ��
	MarioFlagInteractive(_DeltaTime);

	// ������ ����ų
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

				//JumpAttackSound = UEngineSound::SoundPlay("CrouchMoveAttack.wav");
				

				// _Result[i]->GetOwner();/*->Destroy();*/
			}
		}
	}

	// �������� ���������� Block�� Collision ��ȣ�ۿ��� �߻������ִ� ���ǹ�
	std::vector<UCollision*> Collsion;
	if (BodyCollision->CollisionCheck(MarioCollisionOrder::Block, Collsion))
	{
		AActor* Owner = Collsion[0]->GetOwner();

		BlockCommonClass* Block = dynamic_cast<BlockCommonClass*>(Owner);
		Block->BlockColOn(Mode);

		JumpVector = FVector::Zero;
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

void Mario::FlagStop(float _DeltaTime)
{
	AddActorLocation(float4::Down * _DeltaTime * 200.0f);

	std::vector<UCollision*> Result;
	if (true == BodyCollision->CollisionCheck(MarioCollisionOrder::FlagDown, Result))
	{
		StateChange(MarioState::FlagAutoMove);
	}

	//BGMPlay = UEngineSound::SoundPlay("Level1.mp3");
	//BGMPlay.Off();

	//FlagDownSound = UEngineSound::SoundPlay("FlagTouch.wav");



	//DirCheck();
}

void Mario::FlagAutoMove(float _DeltaTime)
{

	JumpVector = FVector::Zero;
	AddActorLocation(float4::Right * 90.0f * _DeltaTime);
	MoveUpdate(_DeltaTime);

	// �������� �������� ���� ��ġ : 13090
	{
		FVector MarioPos = GetActorLocation();
		if (MarioPos.X > 13088)
		{
			MoveVector = FVector::Zero;
			//Destroy(_DeltaTime);
			// �÷��̾ Destroy�� ���������� ���� ġ����
			Renderer->ActiveOff();
			ChangeLevelTime -= _DeltaTime;
		}

		// �������� ����� �ڿ� ���� ������ ����.(3�� ��) <= ����
		// �ð��� ���� �������� == float Time ���� ���� �ʿ��ϴ�.
		// hedder�� �����س��� �׷� ���� �ٷ� ChangeLevelTime �̴�.
		if (0.0f >= ChangeLevelTime)
		{
			GEngine->ChangeLevel("Ending");
		}
		// �� ������ �����ϰڴ°�?
	}

	//DirCheck();
}

void Mario::IdleStart()
{
	JumpVector = FVector::Zero;
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
	FlagDownSound = UEngineSound::SoundPlay("SmallJump.wav");
}

void Mario::FlagStopStart()
{
	BGMPlay = UEngineSound::SoundPlay("Level1.mp3");
	BGMPlay.Off();

	FlagDownSound = UEngineSound::SoundPlay("FlagTouch.wav");
	Renderer->ChangeAnimation(GetAnimationName("FlagStop"));
	//DirCheck();
}

void Mario::FlagAutoMoveStart()
{
	Renderer->ChangeAnimation(GetAnimationName("FlagAutoMove"));
	//DirCheck();
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
	MarioVectorMoveCameraPos(_DeltaTime);
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
		case MarioState::FlagStop:
			FlagStopStart();
			break;
		case MarioState::FlagAutoMove:
			FlagAutoMoveStart();
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
	case MarioState::FlagStop:
		FlagStop(_DeltaTime);
		break;
	case MarioState::FlagAutoMove:
		FlagAutoMove(_DeltaTime);
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




