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
	Map,
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
	Idle,
	Jump,
	//JumpDown,
	DirChange,
	Dead,
	CameraFreeMove,
	FreeMove,
	Run,

};

enum class MonsterState
{
	None,
	Move,
	Dead,
};

enum class MarioMod
{
	Small,
	Big,
	Fire,
};



// Ό³Έν :
class ContentsHelper
{
public:
	static class Mario* MarioPlayer;
	static UWindowImage* ColMapImage;
	//static FVector Gravity;

	//static std::map<PlayerState, std::string> StateList;

	//static bool DownCheck(FVector _NextVector);
	//static bool LeftCheck(FVector _NextVector);
	//static bool RightCheck(FVector _NextVector);
	//static bool BottomCheck(FVector _NextVector);


private:
	// constrcuter destructer
	ContentsHelper();
	~ContentsHelper();
};

