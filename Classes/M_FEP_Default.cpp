#include "Ref2FlyEndFunc.h"

using namespace cocos2d;

CallFunc* M_FEP_Default::getFlyEndFunc(M_ItemEntity* item, SD_ItemEntity* sd)
{
	return CallFunc::create(std::bind(&M_FEP_Default::flyEndFunc, this, item));
}

void M_FEP_Default::flyEndFunc(M_ItemEntity* item)
{
	log((item->getItemName() + " flyEnded!").c_str());
}