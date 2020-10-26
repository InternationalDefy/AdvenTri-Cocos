#include "Ref2DropFunc.h"

using namespace cocos2d;

CallFunc* M_DFP_Flying::getDropFunc(M_ItemState* item, SD_ItemState* sd)
{
	return CallFunc::create(std::bind(&M_DFP_Flying::dropFunc, this, item));
}

void M_DFP_Flying::dropFunc(M_ItemState* item)
{
	log((item->getItemName() + " dropped!").c_str());
}