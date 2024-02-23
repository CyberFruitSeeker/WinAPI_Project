#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include "Physics.h"

// ���� :
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





	// ���� ������ ����� ��� �Լ���
	// Fly�� �ʿ������� ���� �Ǻ�
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Run(float _DeltaTime);
	void IdleStart();
	void RunStart();
	void JumpStart();

	PlayerState State = PlayerState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
	
	// Physics Ŭ������
	// UImageRenderer* Renderer = nullptr;
	// UImageRenderer* ColRenderer = nullptr;
	// �� �ִٴ� �Ϳ� ����

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


	// ���������� ����Ǵ� �߷°� �߷� ���ӵ�


	// ����, ���ư� ��� ������ ���� ��


	// �̵� ���� �߷� ����
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);
	void MoveUpdate(float _DeltaTime);

private:


};
