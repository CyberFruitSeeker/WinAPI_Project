#pragma once

// Ό³Έν :
class ItemBlock
{
public:
	// constrcuter destructer
	ItemBlock();
	~ItemBlock();

	// delete Function
	ItemBlock(const ItemBlock& _Other) = delete;
	ItemBlock(ItemBlock&& _Other) noexcept = delete;
	ItemBlock& operator=(const ItemBlock& _Other) = delete;
	ItemBlock& operator=(ItemBlock&& _Other) noexcept = delete;

protected:

private:

};

