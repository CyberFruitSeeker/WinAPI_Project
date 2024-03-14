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

	void MarioWorldUI();
	void MarioTimeUI();
	void MarioCoinUI();



protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UEngineSoundPlayer BGMPlay;

	float BGMVolume = 1.0f;
	float TimeFlow = 0.1f;








private:

};

