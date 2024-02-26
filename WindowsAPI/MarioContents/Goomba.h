#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include <EngineCore/Actor.h>


// 설명 :
class Goomba : public AActor
{
private:
	static Goomba* ItsGoomba;
public:

	static Goomba* JustGoomba();

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

	void Idle(float _DeltaTime);



	

private:
	
	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;

	// 굼바에게 적용되는 중력과 중력 가속도
	FVector GravityAcc = FVector::Down * 1000.0f;
	FVector GravityVector = FVector::Zero;


	void CalGravityVector(float _DeltaTime);


	void CalLastMoveVector(float _DeltaTime);



	// 굼바의 상태가 어떠니?
	MonsterState StateChange = MonsterState::None;

};

