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
	Block,
	Text,
};

enum class MarioCollisionOrder
{
	Map,
	Monster,
	Player,
	Item,
	Block,
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

// 블럭과 블럭에서 나오는 아이템
// Brick Block과 Item & Coin Block 분리가 필요한가? : 필요하다.
enum class BrickBlockState
{
	Idle,
	MoveUpDown,
	Break,
};

enum class CoinFromBlockState
{
	CoinMoveUp,
};

enum class ItemFromBlockState
{
	ItemMoveUp,
	Idle,
};


// 굼바와 트루파의 애니메이션은 다르게 작동해서 enum class 구분이 필요하다.
enum class GoombaState
{
	None,
	Move,
	Dead,
};

enum class TroopaState
{
	None,
	Move,
	Dead,
};


enum class MarioMode
{
	SmallMario,
	BigMario,
	FireMario,
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

