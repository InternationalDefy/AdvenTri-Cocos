#ifndef __M_DIALOGUE__
#define __M_DIALOGUE__

#include "cocos2d.h"

using namespace cocos2d;

class UI_Item;
class M_LaEmoji;
class M_Dialogue;
//用//注释的语句并非不用，只是暂时未实现，一边删//一边将他们实现。
class Page_Dialogue :public Node
{
private:
	Sprite* _backGround;
	Sprite* _charIcon;
	M_Dialogue* _dialogue;
	FiniteTimeAction* _enterAction;
	FiniteTimeAction* _quitAction;
	Vector<UI_Item*> _diaCtrlitem;
	UI_Item* _laCtrlItemNextPage;
	UI_Item* _laCtrlItemLastPage;
	bool _actived;

	void enterFinishCallback();
	void quitBeginCallback();

	M_LaEmoji* _laEmoji;
private:
	void enterItem();
	void quitItem();
public:

	void enterPage();
	void quitPage();

	/*
	这两个操作是外部接口，其作用是使当前PageDialogue包含的LaEmoji翻页。
	*/
	//void laEmojiNextPage();
	//void laEmojiLastPage();
public:
	void pushItem(UI_Item*);
	void setEnterAction(FiniteTimeAction*);
	void setQuitAction(FiniteTimeAction*);
	void setLaEmoji(M_LaEmoji*);
	void setNextPageLaCtrlItem(UI_Item*);
	void setLastPageLaCtrlItem(UI_Item*);
	void setBackGround(Sprite*);
	void setCharIcon(Sprite*);
	M_Dialogue* getDialogue();
	M_LaEmoji* getLaEmoji(){ return _laEmoji; }
	void setDialogue(M_Dialogue*);
	bool isActived(){ return _actived; }
public:
	Node* getLayer(){ return getParent()->getLayer(); }
	const Node* getLayer() const { return getParent()->getLayer(); }
	void update(float dt);
public:
	bool init();
	/*
	注意事件监听是在其包含的Item里实现的，
	因此Page_Dialogue不包含CallbackParser||DispatcherParser
	*/
	CREATE_FUNC(Page_Dialogue);
};

//用//注释的语句并非不用，只是暂时未实现，一边删//一边将他们实现。
class M_Dialogue :public Node
{
private:
	Vector<Page_Dialogue*> _page;
	Page_Dialogue* _currentPage;
	bool _actived;
	int _onSetLocalZOrder;
	/*
	state是一个状态表示量：
	0：闲置状态。
	1：正在进入状态。
	2：激活状态。
	3：正在退出状态。
	*/
	int _state;
public:
	void enterDialogue();
	void quitDialogue();
	void nextPage(int index);
public:
	void pushPage(Page_Dialogue*);
	void setEnterAction(FiniteTimeAction*);
	void setQuitAction(FiniteTimeAction*);
	int getOnSetLocalZOrder(){ return _onSetLocalZOrder; }
	void setOnSetLocalZOrder(int x){ _onSetLocalZOrder = x; }
	/*
	state是一个状态表示量：
	0：闲置状态。
	1：正在进入状态。
	2：激活状态。
	3：正在退出状态。
	*/
	int getState(){ return _state; }
	void update(float dt);
private:
	FiniteTimeAction* _enterAction;
	FiniteTimeAction* _quitAction;
public:
	bool init();
	CREATE_FUNC(M_Dialogue);
};

#endif