#pragma once
#include <Windows.h>

// ���� :
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

	// �ð������� �����ϰڴ�.
	void TimeCheckStart();

	// ���ݱ��� �� ������?
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

	// �⺻������ CPU�ϵ� ���� ������ ���ο� Count�� �ϴ� �κ��� �����Ѵ�.
	// ���� �������ڸ� ��ǻ�ʹ� �Ѵ� ���� CPU�� �����ϸ鼭 0 1 2 3 4 5 6
	// �ʴ� ������ ���� ���� ������ �����ϰ� ī���� �Ѵ�.
};

