#pragma once
class StarClass
{
public:
	StarClass();
	~StarClass();

	// delete Function
	StarClass(const StarClass& _Other) = delete;
	StarClass(StarClass&& _Other) noexcept = delete;
	StarClass& operator=(const StarClass& _Other) = delete;
	StarClass& operator=(StarClass&& _Other) noexcept = delete;

protected:

private:

};

