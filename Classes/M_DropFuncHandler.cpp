#include "Ref2DropFunc.h"

using namespace cocos2d;

M_DropFuncHandler* M_DropFuncHandler::create()
{
	M_DropFuncHandler* pRet = new(std::nothrow) M_DropFuncHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_DropFuncHandler* s_eventHandler;
M_DropFuncHandler* M_DropFuncHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_DropFuncHandler::create();
	}
	return s_eventHandler;
}
void M_DropFuncHandler::init()
{
	_MapParsers.insert(std::make_pair(AdvenTriEnum::ItemDropCallfunc::DP_C_DEFAULT, M_DFP_Default::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::ItemDropCallfunc::DP_C_FLYING, M_DFP_Flying::create()));
	return;
}

void M_DropFuncHandler::addToItemState(M_ItemState* item, M_DropFuncParser* parser, SD_ItemState* stringData)
{
	item->setDropFunc(parser->getDropFunc(item, stringData));
	return;
}

void M_DropFuncHandler::addDropFuncToItem(M_ItemState* item, SD_ItemState* stringData)
{
	auto k = _MapParsers.at(AdvenTriEnum::changeStringToItemDropCallfunc(stringData->getDropFuncName()));
	addToItemState(item, k, stringData);
	return;
}