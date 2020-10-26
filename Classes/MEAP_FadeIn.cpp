#include "Ref2MenuAnimationHandler.h"

using namespace cocos2d;

FiniteTimeAction* MEAP_FadeIn::getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd)
{
	return Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MEAP_FadeIn::fadein, this, menu, 
		std::atof(sd->getEnterAnimationParam()->at(0).c_str()))),
		DelayTime::create(std::atof(sd->getEnterAnimationParam()->at(0).c_str())));
}

void MEAP_FadeIn::fadein(UI_Menu* menu, float dt)
{
	menu->runAction(FadeIn::create(dt));
	return;
}