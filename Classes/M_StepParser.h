#ifndef __M_STEPCTRL__
#define __M_STEPCTRL__

#include "cocos2d.h"

#define CREATE_STEPCTRL(__TYPE__) \
static __TYPE__* __TYPE__::create() \
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
} \

using namespace cocos2d;

class M_StepParser :public Ref
{
public:
	CREATE_STEPCTRL(M_StepParser);
	virtual void doIt(Entity*, void*);
};

#endif