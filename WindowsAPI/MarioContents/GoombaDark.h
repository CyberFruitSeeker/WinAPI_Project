#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"

// ���� : ���͵����� ������ ���� ���ٴ�ũ���� ���� �����غ���.
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

	// ���͵����� �غ� �� �����








private:

};

