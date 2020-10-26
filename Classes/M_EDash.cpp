#include "Ref2Ebreed.h"

using namespace cocos2d;

void M_EDash::init(SD_Eskill* breed)
{
	_imp = std::atof(breed->_params.at(0).c_str());
}

M_EDash* M_EDash::create(SD_Eskill* breed)
{
	M_EDash* a_Breed = new (std::nothrow)M_EDash();
	if (a_Breed)
	{
		a_Breed->init(breed);
		a_Breed->autorelease();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}

void M_EDash::active()
{
	getOwner()->getPhysicsBody()->applyImpulse(_imp
		* getOwner()->getDashVec2());
}
