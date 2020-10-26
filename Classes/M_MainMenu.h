#ifndef __M_MAINMENU__
#define __M_MAINMENU__

#include "cocos2d.h"

class M_UI_Menu;
class Entity;

using namespace cocos2d;

class M_MainMenu : public Layer
{
private:
	void initAllDataBase();
	M_UI_Menu* _mainMenu;
	M_UI_Menu* _setUpMenu;
	M_UI_Menu* _chooseSaveMenu;
	std::vector<Entity*> _circle;
	std::vector<Entity*> _triangle;
	std::vector<Entity*> _rect;
	void initPhysicsMenu();
	void addCircle();
	void addTriangle();
	void addRect();
public:
	static Scene* createScene();
	bool init();
	void update(float dt);
	CREATE_FUNC(M_MainMenu);

};

#endif