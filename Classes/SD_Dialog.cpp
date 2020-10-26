#include "Ref2LaEmoji.h"

USING_NS_CC;

bool SD_Dialog::init()
{
	_FileName = "";
	_Border = 0;
	_Bspace = 0;
	_LSpace = 0;
	return true;
}

SD_Dialog* SD_Dialog::create(const std::string& name)
{
	SD_Dialog* pRet = new(std::nothrow) SD_Dialog();
	if (pRet)
	{
		pRet->init();
		pRet->_FileName = name;
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

SD_Dialog* SD_Dialog::create()
{
	SD_Dialog* pRet = new(std::nothrow) SD_Dialog();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
