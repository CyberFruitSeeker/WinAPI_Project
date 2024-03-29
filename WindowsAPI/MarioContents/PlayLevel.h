#pragma once
#include <EngineCore/Level.h>
#include <EnginePlatform/EngineSound.h>
#include <EngineCore/Collision.h>

// ���� :
class MarioMap;
class PlayLevel : public ULevel
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;
	void LevelStart(ULevel* _Level) override;
	void LevelEnd(ULevel* _Level) override;

	void BGMSoundControl();

private:
	//MarioMap* Map;
	//MarioUI* ActorUI;
	
	UEngineSoundPlayer BGMPlayer;

	UCollision* FlagColCheck;

};

