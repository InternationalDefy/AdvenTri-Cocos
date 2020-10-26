#include "Ref2LaEmoji.h"

using namespace cocos2d;

CallFunc* M_EEP_Default::getEnterAction(M_Emoji* emoji, float time)
{
	return CallFunc::create(std::bind(&M_EEP_Default::setFunc, this, emoji));
}

void M_EEP_Default::setFunc(M_Emoji* emoji)
{
	emoji->setVisible(TRUE);
	return;
}