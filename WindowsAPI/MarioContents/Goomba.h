#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include <EngineCore/Actor.h>


// ���� :
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

	// ���ٿ��� ����Ǵ� �߷°� �߷� ���ӵ�
	FVector GravityAcc = FVector::Down * 1000.0f;
	FVector GravityVector = FVector::Zero;


	void CalGravityVector(float _DeltaTime);


	void CalLastMoveVector(float _DeltaTime);



	// ������ ���°� ���?
	MonsterState StateChange = MonsterState::None;

};

