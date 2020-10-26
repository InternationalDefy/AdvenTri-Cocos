#ifndef __M_ACITONPARSER__
#define __M_ACITONPARSER__

#include "cocos2d.h"

#define CREATE_ACTIONPARSER(__TYPE__) \
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

class M_ActionParser :public Ref
{
private:
public:
	CREATE_ACTIONPARSER(M_ActionParser);
	virtual FiniteTimeAction* getAction(Node*,std::vector<std::string>);
	virtual FiniteTimeAction* getAction(Node*,Vector<String*>*);
};

#endif