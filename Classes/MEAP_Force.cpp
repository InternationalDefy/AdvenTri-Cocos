#include "Ref2MenuAnimationHandler.h"

using namespace cocos2d;

FiniteTimeAction* MEAP_Force::getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd)
{
	return CallFunc::create(std::bind(&MEAP_Force::setFunc, this, menu));
}

void MEAP_Force::setFunc(UI_Menu* menu)
{
	menu->setOpacity(255);
	return;
}