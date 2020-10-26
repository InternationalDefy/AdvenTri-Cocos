#include "Ref2UseFunc.h"

using namespace cocos2d;

CallFunc* M_UFP_DamageToSelf::getUseFunc(M_ItemState* item, SD_Item* sd)
{
	return CallFunc::create(std::bind(&M_UFP_DamageToSelf::useFunc, this, item, sd));
}

void M_UFP_DamageToSelf::useFunc(M_ItemState* item, SD_Item* sd)
{
	item->getPlayer()->setHurtType(AdvenTriEnum::changeStringToDamageType(sd->getStrings()->at(1)->getCString()));
	item->getPlayer()->setHurtDamage(std::atoi(sd->getStrings()->at(2)->getCString()));
	item->getPlayer()->setDebuffLimit(std::atof(sd->getStrings()->at(3)->getCString()));
	item->getPlayer()->doHurt();
}