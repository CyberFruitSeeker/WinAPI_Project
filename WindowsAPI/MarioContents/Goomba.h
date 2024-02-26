#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "Physics.h"


// ���� :
class Goomba : public Physics
{
private:

public:

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

	void Idle(float _DeltaTime);



	

private:
	
	//UImageRenderer* Renderer = nullptr;
	
	// ���ٿ��� ����Ǵ� �߷°� �߷� ���ӵ�


	// ������ ���°� ���?
	MonsterState StateChange = MonsterState::None;


};

