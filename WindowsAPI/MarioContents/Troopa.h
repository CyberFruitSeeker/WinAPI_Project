#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include "Mario.h"

// ���� :
class Troopa : public AMonster
{
public:
	
	// constrcuter destructer
	Troopa();
	~Troopa();

	// delete Function
	Troopa(const Troopa& _Other) = delete;
	Troopa(Troopa&& _Other) noexcept = delete;
	Troopa& operator=(const Troopa& _Other) = delete;
	Troopa& operator=(Troopa&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;
	UCollision* UpCollision = nullptr;

	// �������� ������ �������� �¿찡 ����Ǵϱ� �׿� ���� �Լ��� �ʿ�
	FVector MoveVector = FVector::Left * 0.1;
	// ������? : Ʈ���Ĵ� ���ٿ� �޸� Left, Right�� �ִ�.

	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;


	// ���� �ִϸ��̼� : Ʈ����
	void StateChange(MonsterState _State);
	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);

	void MoveStart();
	void DeadStart();

	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);

	void MarioJumpAttack() override;


	// Ʈ���Ŀ��� �� �ʿ��� �Լ� == ����� �����ΰ�? : �켱 GetAnimation
	// ������ ���°� �Ǵ� �Ϳ� �ʿ��� �͵� : FSM�� ���õ� ������ CollisionCheck ����??

	// Dir�� üũ�ϰ�, ��ȯ�ϴ� �Լ� �� ��ɵ鵵 �����;� �Ѵ�.
	std::string GetAnimationName(std::string _Name);









private:

	

	

	// Ʈ������ ���°� ���?


};

