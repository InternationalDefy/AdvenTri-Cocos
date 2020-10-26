#include "Ref2UIItem.h"

SD_UIItem* SD_UIItem::create()
{
	SD_UIItem *pRet = new (std::nothrow) SD_UIItem();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_UIItem::init()
{
	_NumberOfSprites = 0;
	_Type = "";
	_ListenerSetName = "";
	return true;
}