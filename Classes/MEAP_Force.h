#ifndef __M_MEAP_FORCE__
#define __M_MEAP_FORCE__

#include "cocos2d.h"
using namespace cocos2d;

class UI_Menu;
class SD_UIMenu; 
class M_MenuAnimationParser;

class MEAP_Force :public M_MenuAnimationParser
{
private:
	void setFunc(UI_Menu* menu);
public:
	CREATE_MENUANIMATION_PARSER(MEAP_Force);
	FiniteTimeAction* getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd);
};

#endif