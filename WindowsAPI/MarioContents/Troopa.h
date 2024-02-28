#pragma once
#include <EngineCore/Actor.h>
#include <EngineCore/Collision.h>
#include "ContentsHelper.h"
#include "StateControl.h"

// ���� :
class Troopa : public StateControl
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

	

	

	// Ʈ������ ���°� ���?


};

