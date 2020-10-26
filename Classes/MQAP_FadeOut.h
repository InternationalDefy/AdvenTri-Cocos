#ifndef __M_MQAO_FADEOUT__
#define __M_MQAO_FADEOUT__

#include "cocos2d.h"
using namespace cocos2d;

class UI_Menu;
class SD_UIMenu;
class M_MenuAnimationParser;

class MQAP_FadeOut :public M_MenuAnimationParser
{
private:
	void fadeOut(UI_Menu* menu, float dt);
public:
	CREATE_MENUANIMATION_PARSER(MQAP_FadeOut);
	FiniteTimeAction* getMenuAnimation(UI_Menu* menu, SD_UIMenu* sd);
};

#endif