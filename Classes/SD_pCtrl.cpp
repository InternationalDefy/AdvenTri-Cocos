#include "Ref2Controller.h"

using namespace cocos2d;

bool SD_pCtrl::init()
{
	_Force = 0;
	_Vangular = 0;
	return true;
}

SD_pCtrl* SD_pCtrl::create()
{
	SD_pCtrl* pRet = new(std::nothrow) SD_pCtrl();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

Ctrl_Player* SD_pCtrl::createPctrlFromSD()
{
	Ctrl_Player* pRet = Ctrl_Player::create();
	pRet->setForce(_Force);
	pRet->setVangular(_Vangular);
	return pRet;
}