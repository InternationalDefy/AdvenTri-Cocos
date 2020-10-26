#ifndef __SYS_EVENT__	
#define __SYS_EVENT__

#include "cocos2d.h"

class Entity;
class UI_Item;
class DB_Event;
class DB_Dispatcher;
class DB_Callback;
class DB_ListenerSet;
class M_EventHandler;
class M_CallbackHandler;
class M_DispatchHandler;
class M_CallbackParser;
class M_DispatchParser;
class M_EventHandlerPhysics;

USING_NS_CC;

class Sys_Event	: public Ref
{
private:

	DB_Event* _eventDB;
	DB_Dispatcher* _dispatcherDB;
	DB_Callback* _callbackDB;
	DB_ListenerSet* _listenerSetDB;
	M_EventHandler* _eventHandler;
	M_CallbackHandler* _callbackHandler;
	M_DispatchHandler* _dispatchHandler;
	
	EventDispatcher* _eventDispatcher;

	M_EventHandlerPhysics* _physicsHandler;

	Vector<M_CallbackParser*> _callbackParsers;
	Vector<M_DispatchParser*> _dispatchParsers;

	virtual void init();

	bool onContactBegin(PhysicsContact& contact);

	static Sys_Event* create();

public:
	static Sys_Event* getInstance();
	
	void setEventDispatcher(EventDispatcher* eventDispatcher)
	{
		_eventDispatcher = eventDispatcher;
	}
	Vector<M_CallbackParser*>* getCallbackParsers()
	{
		return &_callbackParsers;
	}
	Vector<M_DispatchParser*>* getDispatchParsers()
	{
		return &_dispatchParsers;
	}
	void deleteCallbackFunc(M_CallbackParser* del);
	void deleteCallbackFunc(int del);

	void deleteDispatchFunc(M_DispatchParser* del);
	void deleteDispatchFunc(int del);

	void addListenerFunc(Node* node, const std::string& funcName);
	void addCallbackFunc(Node* node, const std::string& funcName);
	void addListenerSetTo(Node* node, const std::string& funcName);
	void addListenerSetTo(Entity* entity, const std::string& funcName);
	void addListenerSetTo(UI_Item* item, const std::string& funcName);

	//相比于直接add，缺少setParentNode
	M_CallbackParser* getCallbackFunc(const std::string& name);
	M_DispatchParser* getListenerFunc(const std::string& name);

	void dispatchEventWithName(const std::string& eventName);

	void addPhysicsListenerToNode(Node* node);
};

#endif