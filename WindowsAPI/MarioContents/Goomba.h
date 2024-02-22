#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"


// 설명 :
class Goomba : public AActor
{
private:
	static Goomba* JustGoomba;

public:
	static Goomba* GetJustGoomba();

	// constrcuter destructer
	Goomba();
	virtual ~Goomba();

	// delete Function
	Goomba(const Goomba& _Other) = delete;
	Goomba(Goomba&& _Other) noexcept = delete;
	Goomba& operator=(const Goomba& _Other) = delete;
	Goomba& operator=(Goomba&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	

private:
	
	UImageRenderer* Renderer = nullptr;
	
	// 굼바에게 적용되는 중력과 중력 가속도


	// 굼바의 상태가 어떠니?
	MonsterState StateChange = MonsterState::None;


};

