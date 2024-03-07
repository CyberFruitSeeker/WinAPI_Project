#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include "Mario.h"

// ���� :
class Troopa : public AMonsterSetting
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
	FVector MoveVector = FVector::Left;
	// ������? : Ʈ���Ĵ� ���ٿ� �޸� Left, Right�� �ִ�.

	TroopaState State = TroopaState::None;
	EActorDir DirState = EActorDir::Left;

	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;
	
	float MoveSpeed = 150.0f;
	//float MaxMoveSpeed = 500.0f;



	std::string CurAnimationName = "None";

	/*float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;*/



	// ���� �ִϸ��̼� : Ʈ����
	void StateChange(TroopaState _State);
	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);

	void MoveStart();
	void DeadStart();
	void DirChangeStart();

	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);
	void DirChange(float _DeltaTime);

	void MarioJumpAttack() override;

	// Ʈ���Ŀ��� �� �ʿ��� �Լ� == ����� �����ΰ�? : �켱 GetAnimation
	std::string GetAnimationName(std::string _Name);
	// ������ ���°� �Ǵ� �Ϳ� �ʿ��� �͵� : FSM�� ���õ� ������ CollisionCheck ����??

	// Dir�� üũ�ϰ�, ��ȯ�ϴ� �Լ� �� ��ɵ鵵 �����;� �Ѵ�.
	void DirCheck();








private:

	

	

	// Ʈ������ ���°� ���?


};

