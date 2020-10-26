#include "Ref2EventPhysics.h"

using namespace cocos2d;
//初始化操作要记住各ParserID对应的Parser
//同时PhysicsParser也要在此注册
void M_EventHandlerPhysics::init()
{
	_eventParsers.pushBack(EPP_PlayerBodyOnEnemy::create());
}

/*
拓展方法：
1：创建一个新的EPP类，模板如EPP
2：在init（如上）方法中加入其注册
3：在PhysicsCallback下文中加入其if
*/
M_EventHandlerPhysics* M_EventHandlerPhysics::create()
{
	auto pRet = new(std::nothrow) M_EventHandlerPhysics();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	return NULL;
}

M_EventHandlerPhysics* s_eventHandlerPhysics;

M_EventHandlerPhysics* M_EventHandlerPhysics::getInstance()
{
	if (!s_eventHandlerPhysics)
	{
		s_eventHandlerPhysics = M_EventHandlerPhysics::create();
	}
	return s_eventHandlerPhysics;
}

void M_EventHandlerPhysics::PhysicsCallback(PhysicsContact& contact)
{
	if (contact.getShapeA()->getTag() == 1 && contact.getShapeB()->getTag() == 2
		|| contact.getShapeA()->getTag() == 2 && contact.getShapeB()->getTag() == 1)
	{
		//PlayerBodyOnEnemy Callback At. 0
		_eventParsers.at(0)->PhysicsCallback(contact);
		return;
	}
	return;
}