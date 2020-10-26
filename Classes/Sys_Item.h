#ifndef __SYS_ITEM__	
#define __SYS_ITEM__

#include "cocos2d.h"

class DB_ItemEntity;
class DB_ItemState;
class M_ItemState;
class M_ItemEntity;
class M_DropFuncHandler;
class M_UseFuncHandler;
class M_FlyEndFuncHandler;

USING_NS_CC;

class Sys_Item : public Ref
{
private:
	DB_ItemEntity* _dbItemEntity;
	DB_ItemState* _dbItemState;
	M_DropFuncHandler* _dpFuncHandler;
	M_UseFuncHandler* _usFuncHandler;
	M_FlyEndFuncHandler* _feFuncHandler;
/*
	M_EventHandler* _eventHandler;
	M_CallbackHandler* _callbackHandler;
	M_DispatchHandler* _dispatchHandler;

	EventDispatcher* _eventDispatcher;

	M_EventHandlerPhysics* _physicsHandler;
	Vector<M_CallbackParser*> _callbackParsers;
	Vector<M_DispatchParser*> _dispatchParsers;
*/
	virtual void init();

	static Sys_Item* create();

public:
	static Sys_Item* getInstance();

	M_ItemState* getItemState(const std::string& name);

	M_ItemEntity* getItemEntity(const std::string& name);
/*
	控制单元在系统中集成
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
	外部访问操作
	void addListenerFunc(Node* node, const std::string& funcName);
	void addCallbackFunc(Node* node, const std::string& funcName);
	void addListenerSetTo(Node* node, const std::string& funcName);
	void dispatchEventWithName(const std::string& eventName);
	void addPhysicsListenerToNode(Node* node);
*/

};

#endif