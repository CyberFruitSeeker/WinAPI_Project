#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "StateControl.h"

// 설명 :
class Troopa : public AActor
{
public:
	
	// constrcuter destructer
	Troopa();
	~Troopa();

	// delete Function
	Troopa(const Troopa& _Other) = delete;
	Troopa(Troopa&& _Other) noexcept = delete;
	Troopa& operator=(const Troopa& _Other) = delete;
	Troopa& operator=(Troopa&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* BodyCollision = nullptr;

	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;

	void CalGravity(float _DeltaTime);


private:

	

	

	// 트루파의 상태가 어떠니?


};

