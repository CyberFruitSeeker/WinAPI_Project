#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
//#include "StateControl.h"

// 설명 :
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

	// 몬스터 애니메이션 : 굼바
	//std::string GetAnimationName(std::string _Name);
	//std::string CurAnimationName = "None";

	void StateUpdate(float _DeltaTime);

	void Idle(float _DeltaTime);
	void Move(float _DeltaTime);
	void Dead(float _DeltaTime);

	// Tick에 돌리기 위한 StateUpdate 함수를 만들기 위한 것들
	MonsterState State = MonsterState::None;
	EActorDir DirState = EActorDir::Left;


	// 굼바에게 적용되는 중력, 가속도 등등의 물리효과
	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	FVector MoveVector = FVector::Zero;
	FVector MoveAccel = FVector::Left * 0.3f;

	void CalMove(float _DeltaTime);

	void CalGravity(float _DeltaTime);





private:





	// 굼바의 상태가 어떠니?
	//MonsterState State = MonsterState::None;

};

