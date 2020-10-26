#ifndef __M_DCCP_LACTRLLEFT__
#define __M_DCCP_LACTRLLEFT__

#include "cocos2d.h"

class SD_Callback;

using namespace cocos2d;

class DCCP_LaCtrlLeft :public M_CallbackParser
{
private:
	std::string _eventName;
public:
	void initWithStringData(SD_Callback* stringData);
	void onCustomEvent(EventCustom* eventCustom);

	static DCCP_LaCtrlLeft* create(SD_Callback* stringData);
};

#endif