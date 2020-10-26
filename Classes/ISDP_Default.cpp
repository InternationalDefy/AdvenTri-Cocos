#include "Ref2DropFunc.h"

using namespace cocos2d;

CallFunc* M_DFP_Default::getDropFunc(M_ItemState* item, SD_ItemState* sd)
{
	return CallFunc::create(std::bind(&M_DFP_Default::dropFunc, this, item));
}

void M_DFP_Default::dropFunc(M_ItemState* item)
{
	log((item->getItemName() + " dropped!").c_str());
}