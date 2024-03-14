#pragma once
#include <EngineCore/Actor.h>
#include <EnginePlatform/EngineSound.h>

// Ό³Έν :
class MarioUI : public AActor
{
public:
	// constrcuter destructer
	MarioUI();
	~MarioUI();

	// delete Function
	MarioUI(const MarioUI& _Other) = delete;
	MarioUI(MarioUI&& _Other) noexcept = delete;
	MarioUI& operator=(const MarioUI& _Other) = delete;
	MarioUI& operator=(MarioUI&& _Other) noexcept = delete;

	void SetMarioWorldUI(std::string_view _UIImageName);
	void SetMarioTimeUI(std::string_view _UIImageName);
	void SetMarioCoinUI(std::string_view _UIImageName);



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UImageRenderer* ColRenderer = nullptr;
	FVector UIScale;





private:



};

