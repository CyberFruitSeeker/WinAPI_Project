#pragma once
#include "ContentsHelper.h"
#include <EngineCore/EngineResourcesManager.h>
#include <EngineCore/Actor.h>

// 설명 :
class Physics : public AActor
{
public:
	// constrcuter destructer
	Physics();
	virtual ~Physics();

	// delete Function
	Physics(const Physics& _Other) = delete;
	Physics(Physics&& _Other) noexcept = delete;
	Physics& operator=(const Physics& _Other) = delete;
	Physics& operator=(Physics&& _Other) noexcept = delete;

protected:
	// 어떤걸 마리오에게 쓰고, 몬스터에게 쓸 것인가?
	void AutoAnimation(UImageRenderer* _Renderer, std::string _Name, int _Start = 0, int _End = 0, float _Time = 0.1f, bool _Routine = true);
	virtual std::string GetAniName(std::string _Name);
	virtual void SetAnimation(std::string _Name);


	virtual bool GravityCheck(float _DeltaTime);
	virtual void MoveResult(float _DeltaTime);


	virtual void StateUpdate(float _DeltaTime) {};
	virtual void SetState(MonsterState _State) {};
	// 블럭, 동전, 아이템에 대한 콜리전 이벤트는 나중에 추가해본다.



	std::string CurAnimationName = "";
	UImageRenderer* Renderer = nullptr;
	UImageRenderer* ColRenderer = nullptr;
	UCollision* BodyCollision = nullptr;
	EActorDir State = EActorDir::Right;


	void InteractiveDirCheck();
	virtual void BeginPlay() = 0;
	virtual void Tick(float _DeltaTime) = 0;
	bool NoDir = false;
	bool IsCollision = false;

	FVector CurSpeed = { 0,0,0,0 };
	FVector GravitySpeed = { 0,0,0,0 };
	FVector XSpeed = { 0,0,0,0 };
	FVector YSpeed = { 0,0,0,0 };
	const FVector BreakSpeed = { 0,0,0,0 };


private:



};

