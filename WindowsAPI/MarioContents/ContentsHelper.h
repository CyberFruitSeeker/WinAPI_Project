#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>
#include <map>

enum MarioRenderOrder
{
	Map,
	Monster,
	Player,
	Text,
};

enum class MarioCollisionOrder
{
	MarioFireBall,
	Monster,
	Player,
};

enum class EActorDir
{
	Left,
	Right,
};

enum class PlayerState
{
	None,
	CameraFreeMove,
	FreeMove,
	Idle,
	Run,
	Jump,
};

enum class MonsterState
{
	None,
	Idle,
	Die,
};


// Ό³Έν :
class ContentsHelper
{
public:
	static class Mario* ItsMeMario;
	static UWindowImage* ColMapImage;
	static FVector Gravity;

	static std::map<PlayerState, std::string> StateList;

	static bool DownCheck(FVector _NextVector);
	static bool LeftCheck(FVector _NextVector);
	static bool RightCheck(FVector _NextVector);



private:
	// constrcuter destructer
	ContentsHelper();
	~ContentsHelper();
};

