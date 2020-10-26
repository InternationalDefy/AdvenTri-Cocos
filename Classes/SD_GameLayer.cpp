#include "Ref2SceneSystem.h"

SD_GameLayer* SD_GameLayer::create()
{
	SD_GameLayer *pRet = new (std::nothrow) SD_GameLayer();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_GameLayer::init()
{
	_NumberOfNpc = 0;
	_NumberOfEnemy = 0;
	_NumberOfBackGround = 0;
	_ListenerSetName = "";
	_GameLayerTag = "";
	return true;
}