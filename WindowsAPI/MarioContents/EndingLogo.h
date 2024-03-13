#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class EndingLogo : public AActor
{
public:
	// constrcuter destructer
	EndingLogo();
	~EndingLogo();

	// delete Function
	EndingLogo(const EndingLogo& _Other) = delete;
	EndingLogo(EndingLogo&& _Other) noexcept = delete;
	EndingLogo& operator=(const EndingLogo& _Other) = delete;
	EndingLogo& operator=(EndingLogo&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;


private:

};

