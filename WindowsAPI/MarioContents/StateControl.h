#pragma once
#include <EngineCore/Actor.h>
#include "ContentsHelper.h"

// ���� :
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


	// ���� Ȥ�� ������������ ���������� ��� �� ���� �����ΰ�?
	// ���Ϳ� ���������� ��ӽ�������� Ŭ������ ���� ������ �� ���ΰ�??
	// �켱�� �߷��� �Ѵ� �ʿ��ϴ� �������� �ົ��.
	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	void CalGravity(float _DeltaTime);





private:


};

