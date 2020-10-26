#include "Ref2Event.h"

using namespace cocos2d;

bool SD_Event::init()
{
	_Param = "";
	_ParamType = "";
	return true;
}

SD_Event* SD_Event::create()
{
	SD_Event* pRet = new(std::nothrow) SD_Event();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
