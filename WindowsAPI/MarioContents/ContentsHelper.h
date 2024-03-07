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
	Item,
	Text,
};

enum class MarioCollisionOrder
{
	Map,
	Monster,
	Player,
	Item,
};

enum class EActorDir
{
	Left,
	None,
	Right,
};

enum class MarioState
{
	None,
	Idle,
	Jump,
	Dead,
	CameraFreeMove,
	FreeMove,
	Run,

};

// 굼바와 트루파의 애니메이션은 다르게 작동해서 enum class 구분이 필요하다.
// 머쉬룸도 우선 구분해주자
enum class GoombaState
{
	None,
	Move,
	//DirChange,
	Dead,
};

enum class MushroomState
{
	None,
	Move,
	//DirChange,
	Dead,
};

enum class TroopaState
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



// 설명 :
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

