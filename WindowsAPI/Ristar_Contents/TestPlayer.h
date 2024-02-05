#pragma once
#include <EngineCore\Actor.h>

// FSM에 대해서 알아보자.
// 한번에 한가지 상태만을 가진다.
// 플레이어가 한번에 1개의 함수만을 실행한다.

enum class PlayState
{
	Idle,
	Move,
	Jump,
};


// 설명 :
class ATestPlayer : public AActor
{
public:
	// constrcuter destructer
	ATestPlayer();
	~ATestPlayer();

	// delete Function
	ATestPlayer(const ATestPlayer& _Other) = delete;
	ATestPlayer(ATestPlayer&& _Other) noexcept = delete;
	ATestPlayer& operator=(const ATestPlayer& _Other) = delete;
	ATestPlayer& operator=(ATestPlayer&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	void StateUpdate(float _DeltaTime);
	void Idle(float _DeltaTime);
	void Jump(float _DeltaTime);
	void Move(float _DeltaTime);
	void GravityCheck(float _DeltaTime);

	PlayState State = PlayState::Idle;

private:
	UImageRenderer* Renderer = nullptr;
	float AnimationTime = 0.0f;
	int AnimationFrame = 0;

	float AlphaTime = 0.0f;
	bool Dir = false;

	float Gravity = 500.0f;
};

