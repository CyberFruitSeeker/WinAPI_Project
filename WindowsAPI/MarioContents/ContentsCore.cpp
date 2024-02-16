#include "ContentsCore.h"
#include "TitleLevel.h"
#include "PlayLevel.h"
#include <EnginePlatform/EngineInput.h>
#include <EngineBase\EngineDirectory.h>
#include <EngineBase\EngineFile.h>
#include <EngineCore\EngineResourcesManager.h>

UContentsCore::UContentsCore()
{
}

UContentsCore::~UContentsCore()
{
}

void UContentsCore::BeginPlay()
{
	// ���� ������ �Ϲ����� �ػ��� 800 / 600�� �ʹ����� ���� �ػ��̴�.
	// MainWindow.SetWindowScale({1280, 720});

	// �߿��Ѱ� ũ�Ⱑ �ƴ϶� ����
	//MainWindow.SetWindowPosition({500, 100});
	//                           1024                960
	MainWindow.SetWindowScale({ 256 * 4/* * 1.5f*/, 240 * 4/* * 1.5f*/ });
	MainWindow.SetWindowPosition({ 800/* * 1.5f*/, 0/* * 1.5f*/ });
	// 1200 

	// 800 16

	UEngineCore::BeginPlay();

	// D:\Project\GM\WIn\App
	UEngineDirectory NewDir;

	// D:\Project\GM\WIn
	NewDir.MoveParent();

	// D:\Project\GM\WIn\ContentsResources
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// ��ο� �ִ� ������ ã�Ƽ� �ڸ��� �Ϳ� �������� ��Ģ�� ���� ���ΰ�
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Player_Right.png", 5, 8);
	UEngineResourcesManager::GetInst().CuttingImage("Player_Left.png", 5, 8);

	// ���ҽ��� ���⼭ �ε��Ҽ��� �ִ�.
	// �츮�� �����ϴ°� Level
	CreateLevel<UTitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Title");
	
}

void UContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);
}
