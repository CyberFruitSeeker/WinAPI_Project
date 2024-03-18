#pragma once
#include <Windows.h>

// 설명 :
class EngineTime
{
public:
	// constrcuter destructer
	EngineTime();
	~EngineTime();

	// delete Function
	EngineTime(const EngineTime& _Other) = delete;
	EngineTime(EngineTime&& _Other) noexcept = delete;
	EngineTime& operator=(const EngineTime& _Other) = delete;
	EngineTime& operator=(EngineTime&& _Other) noexcept = delete;

	// 시간측정을 시작하겠다.
	void TimeCheckStart();

	// 지금까지 얼마 지났어?
	float TimeCheck();

	double GetDeltaTime()
	{
		return DeltaTime;
	}

protected:

private:
	__int64 Count64;
	LARGE_INTEGER Count;
	LARGE_INTEGER PrevTime;
	LARGE_INTEGER CurTime;
	double dCount;
	double DeltaTime;

	// 기본적으로 CPU하드 웨어 적으로 내부에 Count를 하는 부분이 존재한다.
	// 쉽게 설명하자면 컴퓨터는 켜는 순간 CPU가 동작하면서 0 1 2 3 4 5 6
	// 초당 오차가 거의 없을 정도로 일정하게 카운팅 한다.
};

