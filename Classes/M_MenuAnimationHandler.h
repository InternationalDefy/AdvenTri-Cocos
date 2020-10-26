#ifndef __M_MENUACTION_HANDLER__
#define __M_MENUACTION_HANDLER__

#include "cocos2d.h"
#include "Ref_Enum.h"

class M_MenuAnimationParser;
class UI_Menu;
class SD_UIMenu;

using namespace cocos2d;

class M_MenuAnimationHandler :public Ref
{
private:
	void init();
	static M_MenuAnimationHandler* create();
	std::map<AdvenTriEnum::MenuAnimation, M_MenuAnimationParser*> _MapParsers;

	void addMenuEnterAction(UI_Menu* menu, M_MenuAnimationParser* parser, SD_UIMenu* sd);
	void addMenuQuitAction(UI_Menu* menu, M_MenuAnimationParser* parser, SD_UIMenu* sd);
public:
	void handleEandQAnimationToMenu(UI_Menu* menu, SD_UIMenu* sd);
	static M_MenuAnimationHandler* getInstance();
};

#endif