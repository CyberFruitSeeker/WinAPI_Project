#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include "Physics.h"

// 설명 :
class Mario : public Physics
{
public:
	
	// constrcuter destructer
	Mario();
	~Mario();

	// delete Function
	Mario(const Mario& _Other) = delete;
	Mario(Mario&& _Other) noexcept = delete;
	Mario& operator=(const Mario& _Other) = delete;
	Mario& operator=(Mario&& _Other) noexcept = delete;
	void SetState(PlayerState _State);

	static FVector MarioLocation;


protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void MoveLastCamera();

	void DirCheck();

	void StateUpdate(float _DeltaTime);

	void IncreaseSpeed(float _DeltaTime, FVector _Fvector);
	void DecreaseSpeed(float _DeltaTime, FVector _Fvector);





	// 상태 시작의 기능이 담긴 함수들
	// Fly도 필요한지는 추후 판별
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Run(float _DeltaTime);
	void IdleStart();
	void RunStart();
	void JumpStart();

	PlayerState State = PlayerState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
	
	// Physics 클래스에
	// UImageRenderer* Renderer = nullptr;
	// UImageRenderer* ColRenderer = nullptr;
	// 가 있다는 것에 주의

	UCollision* BodyCollision = nullptr;
	UImageRenderer* Renderer = nullptr;

	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	float FreeMoveSpeed = 1500.0f;

	FVector MoveVector = FVector::Zero;
	FVector MoveAcc = FVector::Right * 500.0f;
	float MoveMaxSpeed = 600.0f;
	void AddMoveVector(const FVector& _DirDelta);


	// 마리오에게 적용되는 중력과 중력 가속도


	// 점프, 나아갈 모든 방향의 힘의 합


	// 이동 관련 중력 연산
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);
	void MoveUpdate(float _DeltaTime);

private:


};
