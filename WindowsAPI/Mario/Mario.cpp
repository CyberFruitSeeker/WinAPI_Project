﻿#include <Windows.h>
#include <EngineCore\EngineCore.h>
#include <EnginePlatform\EngineWindow.h>
#include <MarioContents/ContentsCore.h>

// 옛날 엔진들이 유저들에게 엔진을 기동을 쉽게하기 위해서 사용한 방식.

// 사용자가 하고 싶을일을 어떻게 어디에 정의하게 만들거냐?
// 내가 윈도우 크기를 변경하고 싶어.

ENGINESTART(UContentsCore);

// 엔진 스타트 트리거를 당기는 다른 방법
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//	_In_opt_ HINSTANCE hPrevInstance,
//	_In_ LPWSTR    lpCmdLine,
//	_In_ int       nCmdShow)
//{
//	LeakCheck;
//	UContentsCore NewUserCore = UContentsCore();
//	NewUserCore.EngineStart(hInstance);
//}