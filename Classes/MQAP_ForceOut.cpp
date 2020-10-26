#include "Ref2MenuAnimationHandler.h"

using namespace cocos2d;

FiniteTimeAction* MQAP_ForceOut::getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd)
{
	return CallFunc::create(std::bind(&MQAP_ForceOut::forceOut, this, menu));
}

void MQAP_ForceOut::forceOut(UI_Menu* menu)
{
	menu->setOpacity(0);
	return;
}