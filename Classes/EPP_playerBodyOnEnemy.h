#ifndef __EPP_PLAYERBODY_ON_ENEMY__
#define __EPP_PLAYERBODY_ON_ENEMY__

#include "cocos2d.h"

using namespace cocos2d;

class M_EventParserPhysics;

class EPP_PlayerBodyOnEnemy :public M_EventParserPhysics
{
public:
	void PhysicsCallback(PhysicsContact& contact);
	CREATE_FUNC_PHYSICS_PARSER(EPP_PlayerBodyOnEnemy);
};

#endif