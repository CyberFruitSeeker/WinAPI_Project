#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "StateControl.h"

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

	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	void CalGravity(float _DeltaTime);



	

private:
	
	


	





	// ������ ���°� ���?
	MonsterState State = MonsterState::None;

};

