#include "Ref2Ebreed.h"

using namespace cocos2d;

void SD_Ubreed::init()
{
}

SD_Ubreed* SD_Ubreed::create()
{
	SD_Ubreed* a_Breed = new (std::nothrow)SD_Ubreed();
	if (a_Breed)
	{
		a_Breed->init();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}
/*
»¹Òª¸Ä£¡
*/
void SD_Ubreed::addToEntity(M_Enemy* enemy)
{
	for (auto i : _skill_data)
	{
		enemy->addSkill(i->_type,i);
	}
}