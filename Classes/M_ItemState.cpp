#include "Ref2ItemState.h"

bool M_ItemState::init()
{
	_useFunc = NULL;
	_dropFunc = NULL;
	_itemName = "";
	_entityName = "";
	_pickUp = NULL;
	_use = NULL;
	_useTime = 0.0f;
	_player = NULL;
	return true;
}
void M_ItemState::addUseFunc(FiniteTimeAction* func)
{
	if (_useFunc)
	{
		_useFunc = Sequence::create(_useFunc, func, NULL);
		return;
	}
	_useFunc = func;
	return;
}

void M_ItemState::drop()
{
	//run Animation
	//logic update
	//other
	runAction(_dropFunc);
	return;
}

void M_ItemState::use()
{
	//run Animation
	//logic update
	//othere
	runAction(_useFunc);
	return;
}

M_Player* M_ItemState::getPlayer()
{
	if (_player)
	{
		return _player;
	}
	log("We Havent A Player!");
	return NULL;
}