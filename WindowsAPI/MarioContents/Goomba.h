#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
//#include "StateControl.h"

// ���� :
class Goomba : public AActor
{
public:

	//static FVector GoombaLocation;
	//static MonsterState GoombaState;

	// constrcuter destructer
	Goomba();
	~Goomba();

	// delete Function
	Goomba(const Goomba& _Other) = delete;
	Goomba(Goomba&& _Other) noexcept = delete;
	Goomba& operator=(const Goomba& _Other) = delete;
	Goomba& operator=(Goomba&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;
	UCollision* UpCollision = nullptr;

	// ���� �ִϸ��̼� : ����
	void StateChange(float _DeltaTime);

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);

	FVector MoveVector = FVector::Left * 0.1;
	// �������� ������ �������� �¿찡 ����Ǵϱ� �׿� ���� �Լ��� �ʿ�


	// Tick�� ������ ���� StateUpdate �Լ��� ����� ���� �͵�
	// ������ ���°� ���?
	MonsterState State = MonsterState::None;
	EActorDir DirState = EActorDir::Left;


	// ���ٿ��� ����Ǵ� �߷�, ���ӵ� ����� ����ȿ��
	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;


	float MaxMoveSpeed = 350.0f;
	float MoveSpeed = 300.0f;

	void CalMove(float _DeltaTime);

	void CalGravity(float _DeltaTime);

	void StateUpdate(float _DeltaTime);

	




private:




};

