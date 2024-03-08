#pragma once
#include <EngineCore/Actor.h>
#include<EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Mario.h"

// 설명 :
class Mushroom : public AActor
{
public:
	// constrcuter destructer
	Mushroom();
	~Mushroom();

	// delete Function
	Mushroom(const Mushroom& _Other) = delete;
	Mushroom(Mushroom&& _Other) noexcept = delete;
	Mushroom& operator=(const Mushroom& _Other) = delete;
	Mushroom& operator=(Mushroom&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* MushroomCollision = nullptr;
	

	FVector MoveVector = FVector::Right;

	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;
	
	EActorDir DirState = EActorDir::None;

	float MoveSpeed = 200.0f;
	float MaxMoveSpeed = 500.0f;

	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);


	// 머쉬룸에게 필요한 것은?

	// 1. 머쉬룸이 박스에서 솟아난다.
	void MushroomMoveUp(float _DeltaTime);

	// 2. 버섯이 마리오한테 먹혔다.
	void MarioMushroomEat();







private:

};

