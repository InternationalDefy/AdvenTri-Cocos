#ifndef __M_DISPATCH_HANDLER__
#define __M_DISPATCH_HANDLER__

#include "cocos2d.h"

class SD_Dispatcher;
class M_DispatchParser;

using namespace cocos2d;

class M_DispatchHandler :public Ref
{
private:
	void init();
	static M_DispatchHandler* create();
	M_DispatchParser* handleDataType(SD_Dispatcher* stringData);

public:
	static M_DispatchHandler* getInstance();
	M_DispatchParser* getDispatcherWithStringData(SD_Dispatcher* stringData);
	//void addDispatcherWithStringData(SD_Dispatcher* stringData);
};

#endif