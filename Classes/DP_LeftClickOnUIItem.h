#ifndef __M_DP_LEFTCLICKONUIITEM__
#define __M_DP_LEFTCLICKONUIITEM__

#include "cocos2d.h"

class SD_Dispatcher;

using namespace cocos2d;

class DP_LeftClickOnUIItem :public M_DispatchParser
{
private:
	void onMouseDownCallback(Event* event);
public:
	void initWithStringData(SD_Dispatcher* stringData);

	void setParentNode(Node* parent);

	static DP_LeftClickOnUIItem* create(SD_Dispatcher* stringData);
};

#endif