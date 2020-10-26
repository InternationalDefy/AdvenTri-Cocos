#include "Ref2Ebreed.h"

using namespace cocos2d;

void SD_Amor::init()
{
	_defence = 0;
	_hp = 0;
	_type = AdvenTriEnum::AmorType::A_TYPE_BASE;
}

SD_Amor* SD_Amor::create()
{
	SD_Amor* a_Breed = new (std::nothrow)SD_Amor();
	if (a_Breed)
	{
		a_Breed->init();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}

void SD_Amor::addToEntity(M_Enemy* enemy)
{
	auto a_temp = M_Amor::create(this);
	a_temp->addToEnemy(enemy);
}