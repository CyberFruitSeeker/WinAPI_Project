#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"

// 설명 :
class StateControl : public AActor
{
public:
	// constrcuter destructer
	StateControl();
	~StateControl();

	// delete Function
	StateControl(const StateControl& _Other) = delete;
	StateControl(StateControl&& _Other) noexcept = delete;
	StateControl& operator=(const StateControl& _Other) = delete;
	StateControl& operator=(StateControl&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;


	// 몬스터 혹은 마리리오에게 공통적으로 줘야 할 것은 무엇인가?
	// 몬스터와 마리오에게 상속시켜줘야할 클래스를 따로 나눠야 할 것인가??
	// 우선은 중력은 둘다 필요하니 공통으로 줘본다.
	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	void CalGravity(float _DeltaTime);





private:


};

