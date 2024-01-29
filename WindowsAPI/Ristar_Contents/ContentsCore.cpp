#include "ContentsCore.h"
#include "Player.h"
#include "TitleLevel.h"
#include "PlayLevel.h"

ContentsCore::ContentsCore()
	: EngineCore()
{
}

ContentsCore::~ContentsCore()
{
}

// ���ӽ���
void ContentsCore::BeginPlay()
{
	SetFrame(60);

	// �̰����� �ʿ��� ��� ���ҽ��� �α׸� �ε��ϴ� ��� <= ��õ���� �ʴ´�.
	// ���ҽ� ���� �ϰڴٴ°� ��������� ���� ���ҽ��� �̸��� �ε��� ���ڴ�.
	// ���� �����̶�� ���� ���� ����ϴ� ���ҽ��� ����ϰ� �ε��ϴ� ����� ������ �����ϸ鼭
	// ���ÿ� �װ� ����ڰ� ��ġä�� ���ϰ� �ؾ� �Ѵ�.

	// "Title Level" + "�� ����ٰ� ������ �����ϴ�";

	CreateLevel<UTitleLevel>("TitleLevel");
	CreateLevel<UPlayLevel>("PlayLevel");

	ChangeLevel("PlayLevel");
}

void ContentsCore::Tick(float _DeltaTime)
{
	// �÷��̾� �������� �Ѵ�.
}

void ContentsCore::End()
{
}