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

	// �߿��Ѱ� �ػ��� ũ�Ⱑ �ƴ϶� �����̴�.
	//MainWindow.SetWindowPosition({500, 100});
	//                           1024                960
	MainWindow.SetWindowScale({ 256 * 4/* * 1.5f*/, 240 * 4/* * 1.5f*/ });
	MainWindow.SetWindowPosition({ 800/* * 1.5f*/, 0/* * 1.5f*/ });
	// 1200 

	// 800 16

	UEngineCore::BeginPlay();

	// ����̺�:\Project\���ϸ�\WinAPI\App
	UEngineDirectory NewDir;

	// ����̺�:\Project\���ϸ�\WinAPI
	NewDir.MoveParent();

	// ContentsResources ������ �����ϱ�
	NewDir.Move("ContentsResources");

	std::list<UEngineFile> NewList = NewDir.AllFile({ ".png", ".bmp" }, true);

	// �������� ��Ģ�� ���� ���ΰ�?
	// Engine�� ���� �Ǿ��ִ� �̱��� Ȱ���� ���ؼ� GetInst�� ����غ���.
	for (UEngineFile& File : NewList)
	{
		UEngineResourcesManager::GetInst().LoadImg(File.GetFullPath());
	}

	UEngineResourcesManager::GetInst().CuttingImage("Mario_Right.png", 5, 7);
	UEngineResourcesManager::GetInst().CuttingImage("Mario_Left.png", 5, 7);

	// ���� ��� ����� ���� ��ũ
	UEngineResourcesManager::GetInst().CuttingImage("GoombaDark.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Goomba.png", 3, 1);
	UEngineResourcesManager::GetInst().CuttingImage("Troopa_Left.png", 5, 1);





	CreateLevel<UTitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Title");
	
}

void UContentsCore::Tick(float _DeltaTime)
{
	UEngineCore::Tick(_DeltaTime);

	if (true == UEngineInput::IsDown(VK_F2))
	{
		GEngine->EngineDebugSwitch();
	}
}
