#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include "Mario.h"


// ���� :
class Goomba : public AMonsterSetting
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
	void StateChange(GoombaState _State);
	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);

	void MoveStart();
	void DeadStart();

	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);

	void MarioJumpAttack() override;


	// �������� ������ �������� �¿찡 ����Ǵϱ� �׿� ���� �Լ��� �ʿ�
	// �׿� ���� FVector Left �Ӹ��� �ƴ϶�, Right�� �ʿ��ϰڳ�?
	FVector MoveVector = FVector::Right * 0.5f;

	// ���ٿ��� ����Ǵ� �߷�, ���ӵ� ����� ����ȿ��
	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	// Tick�� ������ ���� StateUpdate �Լ��� ����� ���� �͵�
	// ������ State�� ���?
	GoombaState State = GoombaState::None;
	EActorDir DirState = EActorDir::None;









private:




};

