#include "Ref2EventPhysics.h"

using namespace cocos2d;
//��ʼ������Ҫ��ס��ParserID��Ӧ��Parser
//ͬʱPhysicsParserҲҪ�ڴ�ע��
void M_EventHandlerPhysics::init()
{
	_eventParsers.pushBack(EPP_PlayerBodyOnEnemy::create());
}

/*
��չ������
1������һ���µ�EPP�࣬ģ����EPP
2����init�����ϣ������м�����ע��
3����PhysicsCallback�����м�����if
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