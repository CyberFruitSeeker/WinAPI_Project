#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include <EnginePlatform/EngineSound.h>

// 설명 :
class Mario : public AActor
{
public:
	static Mario* GetItsMeMario();
	static Mario* ItsMeMario;

	// constrcuter destructer
	Mario();
	~Mario();

	// delete Function
	Mario(const Mario& _Other) = delete;
	Mario(Mario&& _Other) noexcept = delete;
	Mario& operator=(const Mario& _Other) = delete;
	Mario& operator=(Mario&& _Other) noexcept = delete;

	// 마리오의 small, big, fire(flower)모드
	// Mushroom 클래스에서 알기 위해서 public으로 해둔 상태
	void MarioModeChange(MarioMode _MarioMode);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	// 마리오가 Flag와 상호작용하는 함수들
	void MarioFlagInteractive(float _DeltaTime);
	void MarioFlagCollision(float _DeltaTime);
	void MarioFlagAnimation(float _DeltaTime);


	void DirCheck();


	void StateChange(MarioState _State);
	void StateUpdate(float _DeltaTime);


	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	//void JumpDown(float _DeltaTime);
	void Run(float _DeltaTime);
	void FlagStop(float _DeltaTime);
	void FlagAutoMove(float _DeltaTime);

	// 상태 시작의 기능이 담긴 함수들이다.
	void IdleStart();
	void RunStart();
	void JumpStart();
	void FlagStopStart();
	void FlagAutoMoveStart();

	FVector MarioFlagStopVector = FVector::Zero;
	FVector MarioFlagDown = FVector::Down;

	float MarioFlagDownSpeed = 300.0f;
	float AutoMoveSpeed = 1.0f;

	std::string GetAnimationName(std::string _Name);

	MarioState State = MarioState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";


	// 점프를 한다음 떨어지고 있다는 것은 중력과 점프력이 동시에 작용하고있는 상태이다.
	bool IsJumpDown()
	{
		FVector JPos = (GravityVector + JumpVector);
		return 0 < JPos.Y;
	}


	// 마리오 모드
	MarioMode Mode = MarioMode::SmallMario;
	
	void SmallMario();
	void BigMario();
	void FireMario();


	// 사운드 관련 기능들은 우선 여기에
	UEngineSoundPlayer BGMPlay;

	float BGMVolume = 1.0f;
	float JumpAttackSound = 1.0f;
	float FlagDownSound = 1.0f;
	float StageClearMusic = 1.0f;
	float TroopaShellMoveSound = 1.0f;
	float BlockBreakingSound = 1.0f;





private:
	
	float ChangeLevelTime = 6.0f;
	
	UCollision* BodyCollision = nullptr;
	UCollision* DownCollision = nullptr;
	UImageRenderer* Renderer = nullptr;

	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	// 움직임 기본 속도 & 가속도
	float FreeMoveSpeed = 700.0f;
	float MoveMaxSpeed = 600.0f;
	FVector MoveVector = FVector::Zero;
	FVector MoveAccel = FVector::Right * 450.0f;
	void AddMoveVector(const FVector& _DeltaTime);

	// 마리오에게 적용되는 중력 가속도, 중력 초기화
	FVector GravityAccel = FVector::Down * 1523.0f;
	FVector GravityVector = FVector::Zero;

	// 점프, 나아갈 모든 방향의 힘의 합과 초기화
	FVector JumpPower = FVector::Up * 932.0f;
	FVector JumpVector = FVector::Zero;
	FVector LastMoveVector = FVector::Zero;


	// 이동 관련 중력 연산
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	//void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);

	// 카메라에 따른 움직임
	void MarioVectorMoveCameraPos(float _DeltaTime);
	void MoveCameraMarioPos(float _DeltaTime);

	void MoveUpdate(float _DeltaTime);


	// 어떤 기능을 더 추가할 것인가?
	// moveresult?  
	
	//MarioMap* Map;

	// 마리오가 파이프나 벽에 빠지는 것을 방지하기 위한 좌우아래에 있는 별도의 컬리전





};
