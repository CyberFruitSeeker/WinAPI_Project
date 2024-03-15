#pragma once
#include <EngineCore/Actor.h>
//#include <EnginePlatform/EngineSound.h>

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

	void SetUIBar(std::string_view _UIImageName);
	void SetMarioScroeUI(std::string_view _UIImageName);
	void SetMarioTimeUI(std::string_view _UIImageName);
	void SetCoinScoreUI(std::string_view _UIImageName);
	void SetCoinUI(std::string_view _UIImageName);
	void CoinTwinkleAnimation();
	void SetWolrdStageUI(std::string_view _UIImageName);



protected:


	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	//UImageRenderer* ColRenderer = nullptr;

	FVector UIScale;
	FVector UINumber;
	FVector UITime;



private:
	float TimeFlow = 400.0f;

	std::vector<UImageRenderer*> NumberRenderer;


};

