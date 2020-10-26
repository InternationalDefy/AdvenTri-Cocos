#ifndef __M_UI_LAYER__
#define __M_UI_LAYER__

#include "cocos2d.h"

class UI_Menu;
class M_Dialogue;
class M_GameLayer;

using namespace cocos2d;

class UI_Layer :public Layer
{
private:
	void updatePosition(float dt);
	Vector<M_Dialogue*> _openDialogue;
	Vector<M_Dialogue*> _dialogueVect;
	Map<std::string, M_Dialogue*> _dialogueMap;//_dialogue被addChild了，Vect和Map是不同的方法找到相同的Dialogue，没有被addChild
private:
	void instanceEnterDialogue(M_Dialogue* di);
	void instanceQuitDialogue(M_Dialogue* di);
public:
	void openDialogue(M_Dialogue*);
	void openDialogue(const std::string& name);
	void quitDialogue(M_Dialogue*);
	void quitDialogue(const std::string& name);
	void removeDialogue(M_Dialogue*);
private:
	Vector<UI_Menu*> _menuVect;
	Map<std::string, UI_Menu*> _menuMap;
	Vector<UI_Menu*> _openMenu; //openMenu被addchild了，menus没有。
private:
	void instanceOpenMenu(UI_Menu*);
	void instanceQuitMenu(UI_Menu*);
	//uilayer在创建时将所有的menu装在Map中但是并不addChild只retain（），在需要使用的时候再执行addChild操作。
	//类似于预加载，加载时间换运行效率。
public:
	void openMenu(const std::string& name);
	void openMenu(UI_Menu* menu);
	void quitMenu(const std::string& name);
	void quitMenu(UI_Menu* menu);
	void removeMenu(UI_Menu*);
public:
	Vec2 convertUItoLayer(Vec2 ui);
	Vec2 convertLayertoUI(Vec2 ly);
public:
	void update(float dt);
public:
	bool init();
	CREATE_FUNC(UI_Layer);
public:
	Vec3 getCameraPosition();
	//与实体层沟通部分
private:
	M_GameLayer* _entityLayer;
public:
	M_GameLayer* getEntityLayer()
	{
		return _entityLayer;
	}
	void setEntityLayer(M_GameLayer* layer)
	{
		_entityLayer = layer;
	}
private:
	bool _layerActionRunning; //(default false)
	bool _layerIsPaused; //(default false)
	float _layerActionLimit; //(default 0)
	float _layerActionScheduler;// (default 0)
	void setLayerPause(bool);
	//public:实体层沟通部分/
	/*void entityAction(FiniteTimeAction*, Entity*, float duration)
	{
	_layerActionScheduler = 0; _layerActionLimit = duration; _layerActionRunning = true; if (layerIsPaused) layer->resume(); (getPausedAgainAfterActionTime);
	}*/
	//*pause->非直接引用pause方法，而是使用Scheduler，Action，以及PhysicsWorld的分离暂停？或者直接使用pause方法？有待考证！
	//void update(float dt);
	//{updatePosition(dt); ++updateScheduleLimit(dt); etc...}
public:
	//测试用按钮回调
private:
	M_Dialogue* mk17;
	UI_Menu* m;
public:
	void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif