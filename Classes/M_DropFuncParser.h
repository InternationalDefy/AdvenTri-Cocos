#ifndef __M_DROPFUNC_PARSER__
#define __M_DROPFUNC_PARSER__

#define CREATE_DROPFUNCPARSER(__TYPE__) \
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

class SD_ItemState;
class Sys_Event;
class M_ItemState;

using namespace cocos2d;

class M_DropFuncParser :public Ref
{
private:
public:
	CREATE_DROPFUNCPARSER(M_DropFuncParser);
	virtual CallFunc* getDropFunc(M_ItemState* item, SD_ItemState* stringData);
};

#endif