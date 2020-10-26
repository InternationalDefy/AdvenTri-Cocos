#ifndef __M_MENUACTION_PARSER__
#define __M_MENUACTION_PARSER__

#define CREATE_MENUANIMATION_PARSER(__TYPE__) \
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

using namespace cocos2d;

class UI_Menu;
class SD_UIMenu;

class M_MenuAnimationParser :public Ref
{
private:
public:
	CREATE_MENUANIMATION_PARSER(M_MenuAnimationParser);
	virtual FiniteTimeAction* getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd);
};

#endif