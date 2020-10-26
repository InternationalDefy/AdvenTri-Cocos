#ifndef __M_CP_TESTLOG__
#define __M_CP_TESTLOG__

#include "cocos2d.h"

class SD_Callback;

using namespace cocos2d;

class CP_TestLog :public M_CallbackParser
{
private:
	std::string _log;
	std::string _eventName;
public:
	void initWithStringData(SD_Callback* stringData);
	void onCustomEvent(EventCustom* eventCustom);

	static CP_TestLog* create(SD_Callback* stringData);
};

#endif