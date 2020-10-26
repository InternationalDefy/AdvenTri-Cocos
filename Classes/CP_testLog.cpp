#include "Ref2EventSystem.h"
#include "SD_callback.h"

using namespace cocos2d;

CREATE_CALLBACKPARSER(CP_TestLog);

void CP_TestLog::initWithStringData(SD_Callback* stringData)
{
	_log = stringData->getParams().at(0);
	_eventName = stringData->getUprecivingEventName();
	return;
}

void CP_TestLog::onCustomEvent(EventCustom* eventCustom)
{
	//log(_log.c_str());
	auto sp = Sprite::create("8.png");
	sp->setPosition(Vec2(1280*CCRANDOM_0_1(), 720*CCRANDOM_0_1()));

	getLayer()->addChild(sp, 1);
	updateLimit();
	return;
}