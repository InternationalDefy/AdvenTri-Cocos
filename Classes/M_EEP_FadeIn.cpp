#include "Ref2LaEmoji.h"

using namespace cocos2d;

CallFunc* M_EEP_FadeIn::getEnterAction(M_Emoji* emoji, float time)
{
	return CallFunc::create(std::bind(&M_EEP_FadeIn::fadeInFunc, this, emoji,time));
}

void M_EEP_FadeIn::fadeInFunc(M_Emoji* emoji,float dt)
{
	emoji->setVisible(TRUE);
	emoji->setOpacity(0);
	emoji->runAction(FadeIn::create(dt));
	return;
}