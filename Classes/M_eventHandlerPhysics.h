#ifndef __M_EVENTHANDLER_PHYSICS__M_EVENTHANDLE_PHYSICS____
#define __M_EVENTHANDLER_PHYSICS__

#include "cocos2d.h"

using namespace cocos2d;

class Sys_Event;
class M_EventParserPhysics;

class M_EventHandlerPhysics :public Ref
{
private:
	Sys_Event* _system;
	void init();
	Vector<M_EventParserPhysics*> _eventParsers;
public:
	static M_EventHandlerPhysics* create();
	static M_EventHandlerPhysics* getInstance();
	void PhysicsCallback(PhysicsContact& contact);
};

#endif