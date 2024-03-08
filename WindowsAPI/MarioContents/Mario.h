#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>

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
	void MarioModeChange(MarioMode _MarioMode);


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DirCheck();

	std::string GetAnimationName(std::string _Name);

	void StateChange(MarioState _State);
	void StateUpdate(float _DeltaTime);




	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	//void JumpDown();
	void Run(float _DeltaTime);
	// Fly도 필요한지는 추후 판별

	// 상태 시작의 기능이 담긴 함수들이다.
	void IdleStart();
	void RunStart();
	void JumpStart();

	MarioState State = MarioState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";


	// 점프를 한다음 떨어지고 있다는 것은 중력과 점프력이 동시에 작용하고 있는 것이기 때문에
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



private:
	UCollision* BodyCollision = nullptr;
	UCollision* DownCollision = nullptr;
	UImageRenderer* Renderer = nullptr;

	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	float FreeMoveSpeed = 1500.0f;

	FVector MoveVector = FVector::Zero;
	FVector MoveAccel = FVector::Right * 500.0f;
	float MoveMaxSpeed = 600.0f;
	void AddMoveVector(const FVector& _DeltaTime);

	// 마리오에게 적용되는 중력과 중력 초기화
	FVector GravityAccel = FVector::Down * 1000.0f;
	FVector GravityVector = FVector::Zero;

	// 점프, 나아갈 모든 방향의 힘의 합
	FVector JumpPower = FVector::Up * 770.0f;
	FVector JumpVector = FVector::Zero;
	FVector LastMoveVector = FVector::Zero;


	// 이동 관련 중력 연산
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);

	// 카메라에 따른 움직임
	void MoveLastCameraPos(float _DeltaTime);
	void MoveCameraMarioPos(float _DeltaTime);

	void MoveUpdate(float _DeltaTime);


	// 어떤 기능을 더 추가할 것인가?
	// moveresult?  
	







};
