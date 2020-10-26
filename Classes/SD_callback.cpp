#include "Ref2Callback.h"

using namespace cocos2d;

bool SD_Callback::init()
{
	_UprecivingEventName = "";
	_CallbackFuncType = "";
	_NumberOfParams = 0;
	_FixedProximity = -1;
	_CoolDownTime = 0;
	_LimitedTimes = 0;
	_Swallow = FALSE;
	return true;
}

SD_Callback* SD_Callback::create()
{
	SD_Callback* pRet = new(std::nothrow) SD_Callback();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
