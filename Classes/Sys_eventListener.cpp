#include "Ref2EventSystem.h"
#include "SD_Event.h"

USING_NS_CC;

void Sys_Event::init()
{
	_callbackDB = DB_Callback::getInstance();
	_dispatcherDB = DB_Dispatcher::getInstance();
	_listenerSetDB = DB_ListenerSet::getInstance();
	_eventDB = DB_Event::getInstance();
	_eventHandler = M_EventHandler::getInstance();
	_dispatchHandler = M_DispatchHandler::getInstance();
	_callbackHandler = M_CallbackHandler::getInstance();
	_physicsHandler = M_EventHandlerPhysics::getInstance();
	_eventDispatcher = NULL;
}

CREATE_DB(Sys_Event);

void Sys_Event::dispatchEventWithName(const std::string& eventName)
{
	if (!_eventDB)
	{
		log("Need A Event DB First!");
	}
	EventCustom eventCustom= _eventHandler->getEventFromStringData(_eventDB->getEventSD(eventName), eventName);
	if (!_eventDispatcher)
	{
		_eventDispatcher = Director::getInstance()->getEventDispatcher();
	}
	_eventDispatcher->dispatchEvent(&eventCustom);	
}

void Sys_Event::addListenerFunc(Node* node,const std::string& funcName)
{
	if (!_dispatchHandler)
	{
		log("Need A dispatch Handler First!");
	}
	if (!_dispatcherDB)
	{
		log("Need A dispatch DataBase First!");
	}

	//_dispatchHandler->addDispatchWithStringData(node, _dispatcherDB->getDispatcherSD(funcName));
	
	auto p = _dispatchHandler->getDispatcherWithStringData(_dispatcherDB->getDispatcherSD(funcName));
	p->initEventName(_dispatcherDB->getDispatcherSD(funcName));
	p->setParentNode(node);
	p->setSystem(this);
	_dispatchParsers.pushBack(p);
}
M_DispatchParser* Sys_Event::getListenerFunc(const std::string& funcName)
{
	if (!_dispatchHandler)
	{
		log("Need A dispatch Handler First!");
	}
	if (!_dispatcherDB)
	{
		log("Need A dispatch DataBase First!");
	}

	//_dispatchHandler->addDispatchWithStringData(node, _dispatcherDB->getDispatcherSD(funcName));

	auto p = _dispatchHandler->getDispatcherWithStringData(_dispatcherDB->getDispatcherSD(funcName));
	p->initEventName(_dispatcherDB->getDispatcherSD(funcName));
	p->setSystem(this);
	_dispatchParsers.pushBack(p);
	return p;
}
void Sys_Event::deleteDispatchFunc(M_DispatchParser* del)
{
	if (!_dispatchParsers.contains(del))
	{
		log("This DispatchFunc On delete UNFOUND!");
		return;
	}
	del->removeFromParent();
	_dispatchParsers.eraseObject(del);
}
void Sys_Event::deleteDispatchFunc(int index)
{
	if (index >= _dispatchParsers.size())
	{
		log("No!!!!!!");
		return;
	}
	auto del = _dispatchParsers.at(index);
	deleteDispatchFunc(del);
}

void Sys_Event::addCallbackFunc(Node* node, const std::string& funcName)
{
	if (!_callbackHandler)
	{
		log("Need A callback Handler First!");
	}
	if (!_callbackDB)
	{
		log("Need A callback DataBase First!");
	}
	auto p = _callbackHandler->getCallbackWithStringData(_callbackDB->getCallbackSD(funcName));
	p->setParentNode(node);
	p->setSystem(this);
	_callbackParsers.pushBack(p);
}
//相比于直接add，缺少setParentNode
M_CallbackParser* Sys_Event::getCallbackFunc(const std::string& name)
{
	if (!_callbackHandler)
	{
		log("Need A callback Handler First!");
	}
	if (!_callbackDB)
	{
		log("Need A callback DataBase First!");
	}
	auto p = _callbackHandler->getCallbackWithStringData(_callbackDB->getCallbackSD(name));
	//?不确定以下一句是否删除
	//废话！肯定删除呀！和parentNode有关的操作。
	p->setSystem(this);
	_callbackParsers.pushBack(p);
	return p;
}
void Sys_Event::deleteCallbackFunc(M_CallbackParser* del)
{
	if (!_callbackParsers.contains(del))
	{
		log("This CallbackFunc On delete UNFOUND!");
		return;
	}
	del->removeListener();
	del->removeFromParent();
	_callbackParsers.eraseObject(del);
}
void Sys_Event::deleteCallbackFunc(int index)
{
	if (index >= _callbackParsers.size())
	{
		log("No!!!!!!");
		return;
	}
	auto del = _callbackParsers.at(index);
	deleteCallbackFunc(del);
}

void Sys_Event::addPhysicsListenerToNode(Node* node)
{
	auto lis = EventListenerPhysicsContact::create();
	lis->onContactBegin = CC_CALLBACK_1(Sys_Event::onContactBegin, this);
	node->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis, node);	
}

void Sys_Event::addListenerSetTo(Node* node, const std::string& name)
{
	auto lisSet = _listenerSetDB->getListenerSetSD(name);
	lisSet->addToNode(node);
}
void Sys_Event::addListenerSetTo(UI_Item* item, const std::string& name)
{
	auto lisSet = _listenerSetDB->getListenerSetSD(name);
	lisSet->addToUIItem(item);
}
void Sys_Event::addListenerSetTo(Entity* entity, const std::string& name)
{
	auto lisSet = _listenerSetDB->getListenerSetSD(name);
	lisSet->addToEntity(entity);
}

bool Sys_Event::onContactBegin(PhysicsContact& contact)
{
	_physicsHandler->PhysicsCallback(contact);
	return true;
}
