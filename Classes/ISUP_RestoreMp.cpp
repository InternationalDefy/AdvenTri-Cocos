#include "Ref2UseFunc.h"

using namespace cocos2d;

CallFunc* M_UFP_RestoreMp::getUseFunc(M_ItemState* item, SD_Item* sd)
{
	return CallFunc::create(std::bind(&M_UFP_RestoreMp::useFunc, this, item, sd));
}

void M_UFP_RestoreMp::useFunc(M_ItemState* item, SD_Item* sd)
{
	auto k = sd->getStrings()->at(1)->getCString();
	log("MpRestored ",k);
}