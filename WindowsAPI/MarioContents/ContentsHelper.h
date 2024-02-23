#pragma once
#include <EngineBase\EngineMath.h>
#include <EngineCore\EngineCore.h>
#include <EngineCore\ImageRenderer.h>
#include <map>

enum MarioRenderOrder
{
	Map,
	Player,
	Monster,
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
	None,
	Right,
};

enum class PlayerState
{
	None,
	Crouch,
	Idle,
	FreeMove,
	Run,
	Jump,

};

enum class MonsterState
{
	None,
	Idle,

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

