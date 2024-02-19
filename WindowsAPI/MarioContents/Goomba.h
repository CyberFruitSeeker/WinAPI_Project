#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"


// Ό³Έν :
class Goomba : public AActor
{
private:
	static Goomba* JustGoomba;

public:
	static Goomba* GetJustGoomba;

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

	//


private:

};

