#ifndef __M_UI_MENU__
#define __M_UI_MENU__

#include "cocos2d.h"

class UI_Item;
class Ctrl_Camera;

class UI_Menu :public Node
{
private:
	Map<int, UI_Item*> _itemMap;
	Vector<UI_Item*> _itemVector;
	FiniteTimeAction* _enterAction;
	FiniteTimeAction* _quitAction;
	int _numItems;
	int _onSetLocalZOrder;
	bool _enterInstance;
	/*
	state是一个状态表示量：
	0：闲置状态。
	1：正在进入状态。
	2：激活状态。
	3：正在退出状态。
	*/
	int _state;
public:
	bool init();
	static UI_Menu* create()
	{
		auto p = new(std::nothrow) UI_Menu();
		if (p&&p->init())
		{
			return p;
		}
		delete p;
		p = NULL;
		return NULL;
	}
public:
	void addItem(UI_Item* item);
	void addItem(UI_Item* item, int tag);
private:
	void itemAddInstance(UI_Item* item, int tag, bool useTag);
private:
	void enterItems();
	void quitItems();
public:
	void enterMenu();
	void quitMenu();
	/*
public:
	Vec2 convertVec2ToLayerPosition(Vec2 vec2);
	Vec2 convertVec2ToUiPosition(Vec2 vec2);
	*/
public:
	void update(float dt);

	//setters
public:
	void setEnterAction(FiniteTimeAction* act)
	{
		if (act)
		{
			_enterAction = act;
			_enterAction->retain();
			return;
		}
		log("No!!!!!!!");
		return;
	}
	void setQuitAction(FiniteTimeAction* act)
	{
		if (act)
		{
			_quitAction = act;
			_quitAction->retain();
			return;
		}
		log("No!!!!!!!");
		return;
	}
	void setOnSetLocalZOrder(int z){ _onSetLocalZOrder = z; }
	int getOnSetLocalZOrder(){ return _onSetLocalZOrder; }
	void setEnterInstance(bool i){ _enterInstance = i; }
	bool isEnterInstance(){ return _enterInstance; }
	/*
	state是一个状态表示量：
	0：闲置状态。
	1：正在进入状态。
	2：激活状态。
	3：正在退出状态。
	*/
	int getState(){ return _state; }
};

#endif