#include "ContentsHelper.h"

UWindowImage* ContentsHelper::ColMapImage = nullptr;
static std::map<PlayerState, std::string> StateList;
FVector ContentsHelper::Gravity = { 0.f,1000.0f };

ContentsHelper::ContentsHelper()
{
}

ContentsHelper::~ContentsHelper()
{
}


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

