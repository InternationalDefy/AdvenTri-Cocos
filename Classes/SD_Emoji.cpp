#include "Ref2LaEmoji.h"

bool SD_Emoji::init()
{
	_FileName = "";
	_TimeDelay = 0.0f;
	_AdjustSize = 0.0f;
	_EnterActionType = "";
	return true;
}

SD_Emoji* SD_Emoji::create(const std::string& name)
{
	SD_Emoji* pRet = new(std::nothrow) SD_Emoji();
	if (pRet)
	{
		pRet->init();
		pRet->_FileName = name;
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

SD_Emoji* SD_Emoji::create()
{
	SD_Emoji* pRet = new(std::nothrow) SD_Emoji();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}