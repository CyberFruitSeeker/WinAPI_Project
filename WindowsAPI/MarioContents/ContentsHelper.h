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

// ���� ������ ������ ������
// Brick Block�� Item & Coin Block �и��� �ʿ��Ѱ�? : �ʿ��ϴ�.
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


// ���ٿ� Ʈ������ �ִϸ��̼��� �ٸ��� �۵��ؼ� enum class ������ �ʿ��ϴ�.
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



// ���� :
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

