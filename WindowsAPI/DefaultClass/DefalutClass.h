#pragma once
class DefalutClass
{
public:
	DefalutClass();
	~DefalutClass();

	// delete Function
	DefalutClass(const DefalutClass& _Other) = delete;
	DefalutClass(DefalutClass&& _Other) noexcept = delete;
	DefalutClass& operator=(const DefalutClass& _Other) = delete;
	DefalutClass& operator=(DefalutClass&& _Other) noexcept = delete;

protected:

private:

};

