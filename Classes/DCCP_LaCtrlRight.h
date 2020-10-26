#ifndef __M_DCCP_LACTRLRIGHT__
#define __M_DCCP_LACTRLRIGHT__

#include "cocos2d.h"

class SD_Callback;

using namespace cocos2d;

class DCCP_LaCtrlRight :public M_CallbackParser
{
private:
	std::string _eventName;
public:
	void initWithStringData(SD_Callback* stringData);
	void onCustomEvent(EventCustom* eventCustom);

	static DCCP_LaCtrlRight* create(SD_Callback* stringData);
};

#endif