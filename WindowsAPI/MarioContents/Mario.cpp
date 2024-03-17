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


	// Small Mario 애니메이션
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

	// Small & Big Mario 일때 Collision 변화는 이곳 BeginPlay가 아니라
	// 아래에 있는 FSM에서 관리하게 한다.


	// 굼바와 트루파를 Jump Kill 하기 위한 별도의 DownCollision
	// 마리오 모드가 달라져도 x축 범위는 변함이 없다는 것에 유의
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


// StateUpdate 안에 들어있는 FSM이 Tick에서 돌아간다.
void Mario::Tick(float _DeltaTime)
{

	//AActor::Tick(_DeltaTime);
	StateUpdate(_DeltaTime);
	MoveCameraMarioPos(_DeltaTime);
}

void Mario::BGMSoundControl()
{

}

// 마리오가 지형에 끼이는 것을 방지
void Mario::MarioMagentaShiled(float _DeltaTime)
{



}



void Mario::MarioFlagInteractive(float _DeltaTime)
{
	MarioFlagCollision(_DeltaTime);
	//MarioFlagAnimation(_DeltaTime);
}

// 마리오가 Flag와 Collision 상호작용이 발생했다는 것을 알려준다.
void Mario::MarioFlagCollision(float _DeltaTime)
{
	std::vector<UCollision*> Result;
	if (true == BodyCollision->CollisionCheck(MarioCollisionOrder::FlagUp, Result))
	{
		StateChange(MarioState::FlagStop);
	}

}


// ==================== 마리오 모드 체인지 =====================

// 마리오의 모드가 바뀐다.(컬리전의 y축 크기도 늘어난다.)
// 하지만 기본(시작)상태는 SmallMario 이다.
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



// ====== 카메라 움직임 기능들 ======

// 마리오에게 FVector를 적용하게 하고, 카메라를 움직이게 해준다.
void Mario::MarioVectorMoveCameraPos(float _DeltaTime)
{
	// 카메라는 x축으로만 움직이게 해본다.
	GetWorld()->AddCameraPos(MoveVector * _DeltaTime);
	AddActorLocation(LastMoveVector * _DeltaTime);

	// 
	// 맵에서 원점(0, 0) 이하(마이너스)로 못나가게 하는 코드가
	// Map 클래스 혹은 PlayLevel에 구현되어있다.
	// 하지만 충돌 우려 때문에 우선 주석처리
}

// 마리오의 움직임에 따른 카메라 위치 세팅
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


/// ============== 마리오의 이동에서 키입력과 관련된 기능들 ==============

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


// ====== 키 입력으로 인한 마리오의 움직임과 애니메이션 =======

// 마리오가 기본 상태에서 각동 동작들을 하기 위한 조건문들이 담긴 함수
void Mario::Idle(float _DeltaTime)
{
	if (true == Renderer->IsCurAnimationEnd())
	{
		int a = 0;
	}

	// 마리오가 하고자 하는 동작에 대한 키입력
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

	// 마리오가 점프할때만 깃발과 상호작용 하기 위한 것
	MarioFlagInteractive(_DeltaTime);

	// 마리오 점프킬
	// 상승할때는 점프킬이 발동하면 안되니깐, 이를 위한 조건문을 만든다.
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

	// 마리오가 점프했을때 Block과 Collision 상호작용을 발생시켜주는 조건문
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

	// 마리오가 성벽으로 들어가는 위치 : 13090
	{
		FVector MarioPos = GetActorLocation();
		if (MarioPos.X > 13088)
		{
			MoveVector = FVector::Zero;
			//Destroy(_DeltaTime);
			// 플레이어를 Destroy를 날려버리는 것은 치명적
			Renderer->ActiveOff();
			ChangeLevelTime -= _DeltaTime;
		}

		// 마리오가 사라진 뒤에 엔딩 레벨로 간다.(3초 뒤) <= 조건
		// 시간에 대한 지역변수 == float Time 같은 것이 필요하다.
		// hedder에 구현해놓은 그런 것이 바로 ChangeLevelTime 이다.
		if (0.0f >= ChangeLevelTime)
		{
			GEngine->ChangeLevel("Ending");
		}
		// 이 원리를 이해하겠는가?
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


// ====== 마리오의 중력, 가속도 물리 구현과 계산 =========

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
	// 각종 벡터들을 제로로 만들어서 초기화 시켜줘야 한다.
	LastMoveVector = FVector::Zero;
	LastMoveVector = LastMoveVector + MoveVector;
	LastMoveVector = LastMoveVector + JumpVector;
	LastMoveVector = LastMoveVector + GravityVector;
}


void Mario::MoveUpdate(float _DeltaTime)
{
	// 이동을 하다가 마리오가 땅이나 오브젝트에 처박힐 수 있는 것을 방지하기 위한 것
	CalMoveVector(_DeltaTime);
	CalGravityVector(_DeltaTime);
	CalLastMoveVector(_DeltaTime);
	MarioVectorMoveCameraPos(_DeltaTime);
}




/// ========= 마리오 이미지 셋, 애니메이션, 스테이트 =========

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
	// 마리오의 상태가 변하는 것에 대응하는 함수
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
		//                             2        *  시간      * 500
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




