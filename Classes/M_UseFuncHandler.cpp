#include "Ref2UseFunc.h"

using namespace cocos2d;

M_UseFuncHandler* M_UseFuncHandler::create()
{
	M_UseFuncHandler* pRet = new(std::nothrow) M_UseFuncHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_UseFuncHandler* s_eventHandler;
M_UseFuncHandler* M_UseFuncHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_UseFuncHandler::create();
	}
	return s_eventHandler;
}
void M_UseFuncHandler::init()
{
	_MapParsers.insert(std::make_pair(AdvenTriEnum::ItemUseCallfunc::US_C_RESTORE_HP, M_UFP_RestoreHp::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::ItemUseCallfunc::US_C_RESTORE_MP, M_UFP_RestoreMp::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::ItemUseCallfunc::US_C_DAMAGETO_SELF, M_UFP_DamageToSelf::create()));
	return;
}

void M_UseFuncHandler::addToItemState(M_ItemState* item, M_UseFuncParser* parser, SD_Item* si)
{
	item->addUseFunc(parser->getUseFunc(item, si));
	return;
}

void M_UseFuncHandler::addUseFuncToItem(M_ItemState* item, SD_ItemState* stringData)
{
	int x = stringData->getNumberOfUseFunc();
	if (!x)
	{
		return;
	}
	for (int i = 0; i < x; ++i)
	{
		auto k = _MapParsers.at(
			AdvenTriEnum::changeStringToItemUseCallfunc(
			stringData->getLines()->at(i)->getStrings()->at(0)->getCString()
			));
		addToItemState(item, k, stringData->getLines()->at(i));
	}
	return;
}