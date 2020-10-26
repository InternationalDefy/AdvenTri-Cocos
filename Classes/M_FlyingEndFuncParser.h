#ifndef __M_FLYINGENDFUNC_PARSER__
#define __M_FLYINGENDFUNC_PARSER__

#define CREATE_FLYINGENDFUNCPARSER(__TYPE__) \
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

#include "cocos2d.h"

class SD_ItemEntity;
class Sys_Event;
class M_ItemEntity;

using namespace cocos2d;

class M_FlyEndFuncParser :public Ref
{
private:
public:
	CREATE_FLYINGENDFUNCPARSER(M_FlyEndFuncParser);
	virtual CallFunc* getFlyEndFunc(M_ItemEntity* item, SD_ItemEntity* stringData);
};

#endif