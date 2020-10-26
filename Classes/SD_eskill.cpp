#include "Ref2Ebreed.h"

using namespace cocos2d;

void SD_Eskill::init()
{
	_type = "";
	_positionName = "";
	_cooldown = 0.0f;
}

SD_Eskill* SD_Eskill::create()
{
	SD_Eskill* a_Breed = new (std::nothrow)SD_Eskill();
	if (a_Breed)
	{
		a_Breed->init();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}
