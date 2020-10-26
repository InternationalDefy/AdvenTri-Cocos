#include "Ref2Ebreed.h"

using namespace cocos2d;

void M_ESshot::init(SD_Eskill* breed)
{
	_delay = std::atof(breed->_params.at(0).c_str());
}

M_ESshot* M_ESshot::create(SD_Eskill* breed)
{
	M_ESshot* a_Breed = new (std::nothrow)M_ESshot();
	if (a_Breed)
	{
		a_Breed->init(breed);
		a_Breed->autorelease();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}

void M_ESshot::active()
{
	log("shoted");
}
