#include "Ref2LaEmoji.h"

SD_LaEmoji* SD_LaEmoji::create()
{
	SD_LaEmoji *pRet = new (std::nothrow) SD_LaEmoji();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_LaEmoji::init()
{
	return true;
}