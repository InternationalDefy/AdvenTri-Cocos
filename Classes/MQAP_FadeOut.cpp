#include "Ref2MenuAnimationHandler.h"

using namespace cocos2d;

FiniteTimeAction* MQAP_FadeOut::getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd)
{
	return Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MQAP_FadeOut::fadeOut, this, menu,
		std::atof(sd->getQuitAnimationParam()->at(0).c_str()))),
		DelayTime::create(std::atof(sd->getQuitAnimationParam()->at(0).c_str())));
}

void MQAP_FadeOut::fadeOut(UI_Menu* menu, float dt)
{
	menu->runAction(FadeOut::create(dt));
	return;
}