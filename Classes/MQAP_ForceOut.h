#ifndef __M_MQAP_FORCEOUT__
#define __M_MQAP_FORCEOUT__

#include "cocos2d.h"
using namespace cocos2d;

class UI_Menu;
class SD_UIMenu;
class M_MenuAnimationParser;

class MQAP_ForceOut :public M_MenuAnimationParser
{
private:
	void forceOut(UI_Menu* menu);
public:
	CREATE_MENUANIMATION_PARSER(MQAP_ForceOut);
	FiniteTimeAction* getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd);
};

#endif