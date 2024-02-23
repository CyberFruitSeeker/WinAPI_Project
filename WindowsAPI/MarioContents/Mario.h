#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"
#include <EngineCore/Collision.h>
#include "Physics.h"

// ���� :
class Mario : public Physics
{
public:
	static FVector MarioLocation;
	
	// constrcuter destructer
	Mario();
	~Mario();

	// delete Function
	Mario(const Mario& _Other) = delete;
	Mario(Mario&& _Other) noexcept = delete;
	Mario& operator=(const Mario& _Other) = delete;
	Mario& operator=(Mario&& _Other) noexcept = delete;
	void SetState(PlayerState _State);


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

	void DieStart();
	void Die(float _DeltaTime);

	void Interactive(float _DeltaTime);
	void MoveFun(float _DeltaTime, FVector Accel);




	
	
	
	// Physics Ŭ������
	// UImageRenderer* Renderer = nullptr;
	// UImageRenderer* ColRenderer = nullptr;
	// �� �ִٴ� �Ϳ� ����

	//UCollision* BodyCollision = nullptr;
	//UImageRenderer* Renderer = nullptr;

	// ���������� ����Ǵ� �߷°� �߷� ���ӵ�


	// ����, ���ư� ��� ������ ���� ��


	// �̵� ���� �߷� ����


private:
	PlayerState State = PlayerState::None;

};
