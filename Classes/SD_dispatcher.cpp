#include "Ref2Dispatcher.h"

using namespace cocos2d;

bool SD_Dispatcher::init()
{
	_UpsendingEventName = "";
	_ListeningFuncType = "";
	_LimitTimes = 0;
	_CooldownTime = 0;
	_NumberOfParamas = 0;
	return true;
}

SD_Dispatcher* SD_Dispatcher::create()
{
	SD_Dispatcher* pRet = new(std::nothrow) SD_Dispatcher();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
