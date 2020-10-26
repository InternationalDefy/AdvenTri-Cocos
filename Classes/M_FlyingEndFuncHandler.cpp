#include "Ref2FlyEndFunc.h"

using namespace cocos2d;

M_FlyEndFuncHandler* M_FlyEndFuncHandler::create()
{
	M_FlyEndFuncHandler* pRet = new(std::nothrow) M_FlyEndFuncHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_FlyEndFuncHandler* s_eventHandler;
M_FlyEndFuncHandler* M_FlyEndFuncHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_FlyEndFuncHandler::create();
	}
	return s_eventHandler;
}
void M_FlyEndFuncHandler::init()
{
	_MapParsers.insert(std::make_pair(AdvenTriEnum::FlyEndCallfunc::FE_C_DEFAULT, M_FEP_Default::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::FlyEndCallfunc::FE_C_BLAST, M_FEP_Blast::create()));
	return;
}

void M_FlyEndFuncHandler::addToItemState(M_ItemEntity* item, M_FlyEndFuncParser* parser, SD_ItemEntity* stringData)
{
	item->setFlyingEndFunc(parser->getFlyEndFunc(item, stringData));
	return;
}

void M_FlyEndFuncHandler::addFlyEndFuncToItem(M_ItemEntity* item, SD_ItemEntity* stringData)
{
	auto k = _MapParsers.at(AdvenTriEnum::changeStringToFlyEndCallfunc(stringData->getFlyingEndFuncName()));
	addToItemState(item, k, stringData);
	return;
}