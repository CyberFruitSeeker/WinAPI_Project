#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Monster.h"
#include "Mario.h"
#include <EnginePlatform/EngineSound.h>

// 설명 :
class Goomba : public AMonsterSetting
{
public:

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


	// 파이프에 닿으면 움직임의 좌우가 변경되니깐 그에 대한 함수도 필요
	FVector MoveVector = FVector::Left;

	// 굼바에게 적용되는 중력, 가속도 등등의 물리효과
	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	// Tick에 돌리기 위한 StateUpdate 함수를 만들기 위한 것들
	// 굼바의 State가 어떠니?
	GoombaState State = GoombaState::None;
	EActorDir DirState = EActorDir::None;
	
	float MoveSpeed = 140.0f;
	
	FVector DeadVector = FVector::Zero;

	
	// 몬스터 애니메이션 : 굼바
	void StateChange(GoombaState _State);
	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);

	void MoveStart();
	void DeadStart();

	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);

	void MarioJumpAttack() override;


	









private:
	UEngineSoundPlayer DeadSound;



};

