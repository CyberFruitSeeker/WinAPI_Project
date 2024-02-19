#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>

// ���� :
class Mario : public AActor
{
private:
	static Mario* ItsMeMario;

public:
	static Mario* GetItsMeMario();

	// constrcuter destructer
	Mario();
	~Mario();

	// delete Function
	Mario(const Mario& _Other) = delete;
	Mario(Mario&& _Other) noexcept = delete;
	Mario& operator=(const Mario& _Other) = delete;
	Mario& operator=(Mario&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void DirCheck();

	std::string GetAnimationName(std::string _Name);

	void StateChange(EPlayState _State);
	void StateUpdate(float _DeltaTime);

	void CameraFreeMove(float _DeltaTime);
	void FreeMove(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Run(float _DeltaTime);
	// Fly�� �ʿ������� ���� �Ǻ�

	// ���� ������ ����� ��� �Լ����̴�.
	void IdleStart();
	void RunStart();
	void JumpStart();

	EPlayState State = EPlayState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";
	

private:
	UCollision* BodyCollision = nullptr;

	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	float FreeMoveSpeed = 500.0f;

	FVector MoveVector = FVector::Zero;
	FVector MoveAcc = FVector::Right * 500.0f;
	float MoveMaxSpeed = 500.0f;
	void AddMoveVector(const FVector& _DirDelta);

	// �߷°� ���ӵ�
	FVector GravityAcc = FVector::Down * 1000.0f;
	FVector GravityVector = FVector::Zero;

	// ����, ���ư� ��� ������ ���� ��
	FVector JumpPower = FVector::Up * 750.0f;
	FVector JumpVector = FVector::Zero;
	FVector LastMoveVector = FVector::Zero;

	// �̵�
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);
	void MoveLastMoveVector(float _DeltaTime);
	void MoveUpdate(float _DeltaTime);
};
