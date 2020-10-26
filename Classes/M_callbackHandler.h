#ifndef __M_CALLBACK_HANDLER__
#define __M_CALLBACK_HANDLER__

#include "cocos2d.h"

class SD_Callback;
class M_CallbackParser;

using namespace cocos2d;

class M_CallbackHandler :public Ref
{
private:
	void init();
	static M_CallbackHandler* create();
	M_CallbackParser* handleDataType(SD_Callback* stringData);

public:
	static M_CallbackHandler* getInstance();
	M_CallbackParser* getCallbackWithStringData(SD_Callback* stringData);
};

#endif