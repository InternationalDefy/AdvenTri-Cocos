#include "Ref2SceneSystem.h"

SD_SplashLayer* SD_SplashLayer::create()
{
	SD_SplashLayer *pRet = new (std::nothrow) SD_SplashLayer();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_SplashLayer::init()
{
	_NumberOfSprite = 0;
	return true;
}