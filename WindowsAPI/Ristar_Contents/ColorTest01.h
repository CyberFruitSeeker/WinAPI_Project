#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class ColorTest01 : public AActor
{
public:
	// constrcuter destructer
	ColorTest01();
	~ColorTest01();

	// delete Function
	ColorTest01(const ColorTest01& _Other) = delete;
	ColorTest01(ColorTest01&& _Other) noexcept = delete;
	ColorTest01& operator=(const ColorTest01& _Other) = delete;
	ColorTest01& operator=(ColorTest01&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:

};

