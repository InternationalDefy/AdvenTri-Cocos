#ifndef __UI_SYSTEM__
#define __UI_SYSTEM__

#include "cocos2d.h"

class DB_UIMenu;
class DB_UIItem;
class DB_Dialogue;

class SD_UIItem;
class SD_UIMenu;
class SD_Dialogue;
class SD_PageDialogue;

class UI_Item;
class UI_Menu;
class M_Dialogue;
class Page_Dialogue;

class M_ActionHandler;
class M_MenuAnimationHandler;

class Sys_UI : public Ref
{
public:
	UI_Item* getUIItem(const std::string& name);
	UI_Menu* getUIMenu(const std::string& name);
	M_Dialogue* getDialogue(const std::string& name);

	static Sys_UI* create();
	static Sys_UI* getInstance();
private:
	void init();
	DB_UIMenu* _uimenuDB;
	DB_UIItem* _uiitemDB;
	DB_Dialogue* _dialogueDB;
	M_MenuAnimationHandler* _menuenterHandler;
	M_ActionHandler* _actionHandler;
	UI_Menu* createUiMenuWithStringData(SD_UIMenu* sdu);
	UI_Item* createUiItemWithStringData(SD_UIItem* sdi, UI_Menu* menu, bool indiActive);
	M_Dialogue* createMDialogueWithStringData(SD_Dialogue* sd);
	Page_Dialogue* createPageDialogueWithStringData(SD_PageDialogue* sd);
};

#endif