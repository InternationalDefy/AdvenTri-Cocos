#include "Ref2FlyEndFunc.h"

using namespace cocos2d;

CallFunc* M_FEP_Blast::getFlyEndFunc(M_ItemEntity* item, SD_ItemEntity* sd)
{
	return CallFunc::create(std::bind(&M_FEP_Blast::flyEndFunc, this, item));
}

void M_FEP_Blast::flyEndFunc(M_ItemEntity* item)
{
	//use Params mAybe
	log("Blast!");
}