#ifndef __M_DP_LEFTCLICKONTHIS__
#define __M_DP_LEFTCLICKONTHIS__

#include "cocos2d.h"

class SD_Dispatcher;

using namespace cocos2d;

class DP_LeftClickOnThis :public M_DispatchParser
{
private:
	void onMouseDownCallback(Event* event);
public:
	void initWithStringData(SD_Dispatcher* stringData);

	void setParentNode(Node* parent);

	static DP_LeftClickOnThis* create(SD_Dispatcher* stringData);
};

#endif