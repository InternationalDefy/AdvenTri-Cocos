#ifndef __M_EVENTPARSER_PHYSICS__
#define __M_EVENTPARSER_PHYSICS__

#include "cocos2d.h"

#define CREATE_FUNC_PHYSICS_PARSER(__TYPE__) \
static __TYPE__* create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
	    { \
        return pRet; \
	    } \
	    else \
	    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
	    } \
}

using namespace cocos2d;

class M_EventParserPhysics :public Ref
{
public:
	virtual void PhysicsCallback(PhysicsContact& contact);
	CREATE_FUNC_PHYSICS_PARSER(M_EventParserPhysics);
};

#endif