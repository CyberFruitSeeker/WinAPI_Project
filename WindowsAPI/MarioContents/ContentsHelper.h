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
	FireBall,
	Monster,
	Player,
};

enum class MonsterCollisionOreder
{
	Map,
	ColToMario,

};

enum class EActorDir
{
	Left = -1,
	None = 0,
	Right = 1,
};

enum class PlayerState
{
	None,
	Idle,
	Move,
	Jump,
	DirChange,
	Interactive,
	Dead,
	End,
	EndMove,
	Changing,
};

enum class MarioMod
{
	Small,
	Big,
	Fire,
};

enum class MonsterState
{
	None,
	Idle,
	MonsterDie,

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
	static bool BottomCheck(FVector _NextVector);


private:
	// constrcuter destructer
	ContentsHelper();
	~ContentsHelper();
};

