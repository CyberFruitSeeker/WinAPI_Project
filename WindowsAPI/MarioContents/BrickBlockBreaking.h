#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "Mario.h"
#include "BrickBlock.h"

// Ό³Έν :
class BrickBlockBreaking : public AActor
{
public:
	// constrcuter destructer
	BrickBlockBreaking();
	~BrickBlockBreaking();

	// delete Function
	BrickBlockBreaking(const BrickBlockBreaking& _Other) = delete;
	BrickBlockBreaking(BrickBlockBreaking&& _Other) noexcept = delete;
	BrickBlockBreaking& operator=(const BrickBlockBreaking& _Other) = delete;
	BrickBlockBreaking& operator=(BrickBlockBreaking&& _Other) noexcept = delete;



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


	UImageRenderer* Renderer = nullptr;
	UCollision* BreakCollision = nullptr;

	float BreakSpeed = 10.0f;

	void BreakAnimation(float _DeltaTime);

	void BlockMarioCol(float _DeltaTime);






private:

};

