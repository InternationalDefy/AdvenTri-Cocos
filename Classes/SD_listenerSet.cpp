#include "Ref2ListenerSet.h"

using namespace cocos2d;

bool SD_ListenerSet::init()
{
	_NumberOfDispatcher = 0;
	_NumberOfCallback = 0;
	return true;
}

SD_ListenerSet* SD_ListenerSet::create()
{
	SD_ListenerSet* pRet = new(std::nothrow) SD_ListenerSet();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

void SD_ListenerSet::addToNode(Node* node)
{
	for (auto i = 0; i < _NumberOfDispatcher; ++i)
	{
		Sys_Event::getInstance()->addListenerFunc(node, _DispatcherName.at(i));
	}
	for (auto i = 0; i < _NumberOfCallback; ++i)
	{
		Sys_Event::getInstance()->addCallbackFunc(node, _CallbackName.at(i));
	}
}

void SD_ListenerSet::addToEntity(Entity* entity)
{
	for (auto i = 0; i < _NumberOfDispatcher; ++i)
	{
		auto p = Sys_Event::getInstance()->getListenerFunc(_DispatcherName.at(i));
		p->setParentNode(entity);
		entity->pushDispatchParser(p);
	}
	for (auto i = 0; i < _NumberOfCallback; ++i)
	{
		auto p = Sys_Event::getInstance()->getCallbackFunc(_CallbackName.at(i));
		p->setParentNode(entity);
		entity->pushCallbackParser(p);
	}
}
void SD_ListenerSet::addToUIItem(UI_Item* item)
{
	for (auto i = 0; i < _NumberOfDispatcher; ++i)
	{
		auto p = Sys_Event::getInstance()->getListenerFunc(_DispatcherName.at(i));
		//p->setParentNode(entity);
		item->pushDispatchParser(p);
	}
	for (auto i = 0; i < _NumberOfCallback; ++i)
	{
		auto p = Sys_Event::getInstance()->getCallbackFunc(_CallbackName.at(i));
		//p->setParentNode(entity);
		item->pushCallbackParser(p);
	}
}