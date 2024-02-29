#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"

// 설명 : 몬스터들한테 적용할 것은 굼바다크한테 먼저 실험해보자.
class GoombaDark : public AActor
{
public:
	// constrcuter destructer
	GoombaDark();
	~GoombaDark();

	// delete Function
	GoombaDark(const GoombaDark& _Other) = delete;
	GoombaDark(GoombaDark&& _Other) noexcept = delete;
	GoombaDark& operator=(const GoombaDark& _Other) = delete;
	GoombaDark& operator=(GoombaDark&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;

	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	void CalGravity(float _DeltaTime);

	// 몬스터들한테 해볼 것 실험용








private:

};

