#include "EngineString.h"
#include <Windows.h>
#include "EngineDebug.h"

UEngineString::UEngineString() 
{
}

UEngineString::~UEngineString() 
{
}

std::wstring UEngineString::AnsiToUniCode(std::string_view _View)
{
	int Size = MultiByteToWideChar(CP_ACP, 0, _View.data(), static_cast<int>(_View.size()), nullptr, 0);

	if (0 == Size)
	{
		MsgBoxAssert("���ڿ� ��ȯ�� �����߰ų� ũ�Ⱑ 0�� ���ڿ��� �־�����ϴ�");
		return L"";
	}

	// std::string�̳� std::wstring ���ο� std::vector<char>
	// std::vector<char> Vector;
	// Vector[0] => char&
	// &Vector[0] => *char

	//wchar_t* Arr = new wchar_t[Size];
	//delete Arr;
	std::wstring Result;
	Result.resize(Size);

	// ��ȯ�Ǿ��� ������ �����µ�.
	Size = MultiByteToWideChar(CP_ACP, 0, _View.data(), static_cast<int>(_View.size()), &Result[0], Size);

	if (0 == Size)
	{
		MsgBoxAssert("���ڿ� ��ȯ�� �����߰ų� ũ�Ⱑ 0�� ���ڿ��� �־�����ϴ�");
		return L"";
	}

	// �ڿ������� RValue ���۷����� �Ǵϱ� �߰� ������ �̷������ �ʴ´�.
	return Result;
}

std::string UEngineString::ToUpper(std::string_view View)
{
	std::string Name = View.data();

	for (char& _Ch : Name)
	{
		_Ch = std::toupper(_Ch);
	}

	return Name;
}