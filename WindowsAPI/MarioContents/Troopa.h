#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"

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




private:

	UImageRenderer* Renderer = nullptr;
	UCollision* TroopaCollision = nullptr;

	FVector GravityAcc = FVector::Down * 2.0f;
	FVector GravityVector = FVector::Zero;



	// 트루파의 상태가 어떠니?


};

