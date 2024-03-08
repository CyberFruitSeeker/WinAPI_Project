#pragma once

// Ό³Έν :
class BrickBlock
{
public:
	// constrcuter destructer
	BrickBlock();
	~BrickBlock();

	// delete Function
	BrickBlock(const BrickBlock& _Other) = delete;
	BrickBlock(BrickBlock&& _Other) noexcept = delete;
	BrickBlock& operator=(const BrickBlock& _Other) = delete;
	BrickBlock& operator=(BrickBlock&& _Other) noexcept = delete;

protected:

private:

};

