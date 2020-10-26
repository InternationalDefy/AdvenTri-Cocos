#ifndef __M_EVENT_HANDLER__
#define __M_EVENT_HANDLER__

#include "cocos2d.h"

class SD_Event;

using namespace cocos2d;

class M_EventHandler :public Ref
{
public:
	void init();
	static M_EventHandler* create();
	void handleDataType(EventCustom* eventCustom,SD_Event* stringData);

public:
	static M_EventHandler* getInstance();
	EventCustom getEventFromStringData(SD_Event* stringData, const std::string& name);
};

#endif