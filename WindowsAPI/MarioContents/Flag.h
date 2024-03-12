#pragma once
#include <EngineCore/Actor.h>


// Ό³Έν :
class Flag : public AActor
{
public:
	// constrcuter destructer
	Flag();
	~Flag();

	// delete Function
	Flag(const Flag& _Other) = delete;
	Flag(Flag&& _Other) noexcept = delete;
	Flag& operator=(const Flag& _Other) = delete;
	Flag& operator=(Flag&& _Other) noexcept = delete;

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

	UImageRenderer* Renderer = nullptr;
	UCollision* FlagUpCollision = nullptr;
	UCollision* FlagDownCollision = nullptr;

	void GoToLextLevel(float _DeltaTime);



private:

};

