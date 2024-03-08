#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>

// ���� :
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

	// �������� small, big, fire(flower)���
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
	// Fly�� �ʿ������� ���� �Ǻ�

	// ���� ������ ����� ��� �Լ����̴�.
	void IdleStart();
	void RunStart();
	void JumpStart();

	MarioState State = MarioState::None;
	EActorDir DirState = EActorDir::Right;
	std::string CurAnimationName = "None";


	// ������ �Ѵ��� �������� �ִٴ� ���� �߷°� �������� ���ÿ� �ۿ��ϰ� �ִ� ���̱� ������
	bool IsJumpDown()
	{
		FVector JPos = (GravityVector + JumpVector);
		return 0 < JPos.Y;
	}


	// ������ ���
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

	// ���������� ����Ǵ� �߷°� �߷� �ʱ�ȭ
	FVector GravityAccel = FVector::Down * 1000.0f;
	FVector GravityVector = FVector::Zero;

	// ����, ���ư� ��� ������ ���� ��
	FVector JumpPower = FVector::Up * 770.0f;
	FVector JumpVector = FVector::Zero;
	FVector LastMoveVector = FVector::Zero;


	// �̵� ���� �߷� ����
	void CalLastMoveVector(float _DeltaTime);
	void CalMoveVector(float _DeltaTime);
	void CalJumpVector(float _DeltaTime);
	void CalGravityVector(float _DeltaTime);

	// ī�޶� ���� ������
	void MoveLastCameraPos(float _DeltaTime);
	void MoveCameraMarioPos(float _DeltaTime);

	void MoveUpdate(float _DeltaTime);


	// � ����� �� �߰��� ���ΰ�?
	// moveresult?  
	







};
