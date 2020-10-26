#include "Ref2Animation.h"

using namespace cocos2d;

bool SD_Animation::init()
{
	_NumberOfParams = 0;
	_AnimationTypeName = "";
	return true;
}

SD_Animation* SD_Animation::create()
{
	SD_Animation* pRet = new(std::nothrow) SD_Animation();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}