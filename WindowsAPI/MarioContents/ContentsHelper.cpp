#include "ContentsHelper.h"

UWindowImage* ContentsHelper::ColMapImage = nullptr;
//static std::map<PlayerState, std::string> StateList;
//FVector ContentsHelper::Gravity = { 0.f,1000.0f };

ContentsHelper::ContentsHelper()
{
}

ContentsHelper::~ContentsHelper()
{
}


// 마리오가 벽에 끼거나 박히는 것을 방지하기 위한 것들

bool ContentsHelper::DownCheck(FVector _NextVector)
{
	return false;
}

bool ContentsHelper::LeftCheck(FVector _NextVector)
{
	return false;
}

bool ContentsHelper::RightCheck(FVector _NextVector)
{
	return false;
}

bool ContentsHelper::BottomCheck(FVector _NextVector)
{
	return false;
}

