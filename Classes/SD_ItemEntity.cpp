#include "Ref2ItemEntity.h"

using namespace cocos2d;

bool SD_ItemEntity::init()
{
	_ItemName = "";
	_TextureName = "";
	_ItemState = "";
	_DropAnimateName = "";
	_DropDelay = 0.0f;
	_TimeExist = 0.0f;
	_PhysicsBodyName = "";
	_FlyingController = "";
	_DropController = "";
	_FlyingEndFuncName = "Default";
	_NumberOfFlyEndFuncParams = 0;
	return true;
}

SD_ItemEntity* SD_ItemEntity::create()
{
	SD_ItemEntity* pRet = new(std::nothrow) SD_ItemEntity();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
