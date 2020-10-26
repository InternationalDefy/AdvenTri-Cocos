#include "Ref2Dialogue.h"
using namespace cocos2d;

SD_Dialogue* SD_Dialogue::create()
{
	SD_Dialogue *pRet = new (std::nothrow) SD_Dialogue();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool SD_Dialogue::init()
{
	_OnSetPosition = Vec2(0, 0);
	_NumberOfPages = 0;
	_Opacity = 255;
	_EnterActionType = "";
	_ExitActionType = "";
	return TRUE;
}

SD_PageDialogue* SD_PageDialogue::create()
{
	SD_PageDialogue *pRet = new(std::nothrow) SD_PageDialogue();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool SD_PageDialogue::init()
{
	_BackGroundName = "";
	_CharIconName = "";
	_LaEmojiName = "";
	_NumberOfItems = 0;
	_LaCtrlName1 = "";
	_LaCtrlName2 = "";
	_LaCtrlOpacity1 = 255;
	_LaCtrlOpacity2 = 255;
	_CharIconOffset = Vec2(0, 0);
	_LaEmojiPosition = Vec2(0, 0);
	_LaCtrlOffSet1 = Vec2(0, 0);
	_LaCtrlOffSet2 = Vec2(0, 0);
	_EnterActionType = "";
	_ExitActionType = "";
	return TRUE;
}