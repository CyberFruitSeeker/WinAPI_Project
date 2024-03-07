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
	UCollision* BodyCollision = nullptr;

	FVector MoveVector = FVector::Right * 0.5;

	FVector GravityAccel = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;
	
	
	EActorDir DirState = EActorDir::None;

	void StateUpdate(float _DeltaTime);

	void CalMove(float _DeltaTime);
	void CalGravity(float _DeltaTime);



	// 머쉬룸에게 필요한 것은?
	void DirCheck();

	void MushroomMoveUp();









private:

};

