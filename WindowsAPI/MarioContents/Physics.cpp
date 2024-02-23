#include "Physics.h"
#include "Mario.h"
#include <EngineCore/EngineResourcesManager.h>
#include <MarioContents/ContentsHelper.h>


Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::Tick(float _DeltaTime)
{

}

void Physics::InteractiveDirCheck()
{
	// Player에게 주고받는 네이밍 : ItsMeMario..?

	if (Mario::MarioLocation.X < GetActorLocation().X)
	{
		DirState = EActorDir::Right;
	}
	else
	{
		DirState = EActorDir::Left;
	}



}


void Physics::AutoAnimation(UImageRenderer* _Renderer, std::string _Name, int _Start, int _End, float _Time, bool _Routine)
{
	std::string CurName = GetName();
	if (NoDir) {
		_Renderer->CreateAnimation(_Name, CurName + ".png", _Start, _End, _Time, _Routine);
		return;
	}
	_Renderer->CreateAnimation(_Name + "_Right", CurName + "_Right.png", _Start, _End, _Time, _Routine);
	_Renderer->CreateAnimation(_Name + "_Left", CurName + "_Left.png", _Start, _End, _Time, _Routine);
	return;
}

std::string Physics::GetAniName(std::string _Name)
{
	std::string GoName = "";

	switch (DirState)
	{
	case EActorDir::Left:
		GoName = "_Left";
		break;
	case EActorDir::None:
		break;
	case EActorDir::Right:
		GoName = "_Right";
		break;
	default:
		break;
	}

	if (NoDir)
	{
		GoName = "";
	}

	CurAnimationName = _Name;

	return _Name + GoName;
}

void Physics::SetAnimation(std::string _Name)
{
	std::string AniName = GetAniName(_Name);
	Renderer->ChangeAnimation(AniName);
}


bool Physics::GravityCheck(float _DeltaTime)
{
	FVector CurLocation = GetActorLocation();
	GravitySpeed += ContentsHelper::Gravity * _DeltaTime;

	Color8Bit Color_Right = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX() + 28, GetActorLocation().iY(), Color8Bit::MagentaA);
	Color8Bit Color_Left = ContentsHelper::ColMapImage->GetColor(GetActorLocation().iX() - 28, GetActorLocation().iY(), Color8Bit::MagentaA);
	
	if (Color_Right == Color8Bit(255, 0, 255, 0) || Color_Left == Color8Bit(255, 0, 255, 0) || IsCollision == true)
	{
		GravitySpeed = BreakSpeed;
		YSpeed = BreakSpeed;
		return false;

	}
	
	return false;
}

void Physics::MoveResult(float _DeltaTime)
{
	CurSpeed += XSpeed;
	CurSpeed += YSpeed;
	CurSpeed += GravitySpeed;
	CurSpeed = BreakSpeed;
	AddActorLocation(CurSpeed * _DeltaTime);
}





