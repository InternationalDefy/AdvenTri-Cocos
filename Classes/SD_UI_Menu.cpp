#include "Ref2UIMenu.h"

SD_UIMenu* SD_UIMenu::create()
{
	SD_UIMenu *pRet = new (std::nothrow) SD_UIMenu();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_UIMenu::init()
{
	_CallActived = 0;
	_ZOrder = 0;
	_NumberOfItems = 0;
	_EnterAnimationType = "";
	_QuitAnimationType = "";
	_NumberOfEnterAnimationParams = 0;
	_NumberOfQuitAnimationParams = 0;
	return true;
}