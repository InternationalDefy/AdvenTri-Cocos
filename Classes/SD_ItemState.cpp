#include "Ref2ItemState.h"

using namespace cocos2d;

bool SD_ItemState::init()
{
	_ItemName = "";
	_UISetName = "";
	_ItemEntity = "";
	_UsingAnimateName = "";
	_PickUpAnimate = "";
	_UsingTime = 0.0f;
	_DropFuncName = "";
	_NumberOfDropFuncParams = 0;
	_NumberOfUseFunc = 0;
	return true;
}

SD_ItemState* SD_ItemState::create()
{
	SD_ItemState* pRet = new(std::nothrow) SD_ItemState();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
