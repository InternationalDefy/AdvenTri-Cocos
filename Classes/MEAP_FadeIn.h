#ifndef __M_MEAP_FADEIN__
#define __M_MEAP_FADEIN__

#include "cocos2d.h"
using namespace cocos2d;

class UI_Menu;
class SD_UIMenu;
class M_MenuAnimationParser;

class MEAP_FadeIn :public M_MenuAnimationParser
{
private:
	void fadein(UI_Menu* menu,float dt);
public:
	CREATE_MENUANIMATION_PARSER(MEAP_FadeIn);
	FiniteTimeAction* getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd);
};

#endif