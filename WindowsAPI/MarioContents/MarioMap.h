#pragma once
#include <EngineCore/Actor.h>

// Ό³Έν :
class MarioMap : public AActor
{
public:
	// constrcuter destructer
	MarioMap();
	~MarioMap();

	// delete Function
	MarioMap(const MarioMap& _Other) = delete;
	MarioMap(MarioMap&& _Other) noexcept = delete;
	MarioMap& operator=(const MarioMap& _Other) = delete;
	MarioMap& operator=(MarioMap&& _Other) noexcept = delete;

	void SetMapImage(std::string_view _MarioMapImageName);
	void SetColMapImage(std::string_view _MarioMapImageName);

	void SwitchDebug();

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* Renderer = nullptr;
	UImageRenderer* ColRenderer = nullptr;
};

