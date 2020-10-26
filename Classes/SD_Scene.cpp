#include "Ref2SceneSystem.h"

SD_Scene* SD_Scene::create()
{
	SD_Scene *pRet = new (std::nothrow) SD_Scene();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_Scene::init()
{
	_NumberOfGameLayer = 0;
	_NumberOfSplashScene = 0;
	return true;
}