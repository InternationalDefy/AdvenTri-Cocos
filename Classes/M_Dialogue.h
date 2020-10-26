#ifndef __M_DIALOGUE__
#define __M_DIALOGUE__

#include "cocos2d.h"

using namespace cocos2d;

class UI_Item;
class M_LaEmoji;
class M_Dialogue;
//��//ע�͵���䲢�ǲ��ã�ֻ����ʱδʵ�֣�һ��ɾ//һ�߽�����ʵ�֡�
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
	�������������ⲿ�ӿڣ���������ʹ��ǰPageDialogue������LaEmoji��ҳ��
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
	ע���¼����������������Item��ʵ�ֵģ�
	���Page_Dialogue������CallbackParser||DispatcherParser
	*/
	CREATE_FUNC(Page_Dialogue);
};

//��//ע�͵���䲢�ǲ��ã�ֻ����ʱδʵ�֣�һ��ɾ//һ�߽�����ʵ�֡�
class M_Dialogue :public Node
{
private:
	Vector<Page_Dialogue*> _page;
	Page_Dialogue* _currentPage;
	bool _actived;
	int _onSetLocalZOrder;
	/*
	state��һ��״̬��ʾ����
	0������״̬��
	1�����ڽ���״̬��
	2������״̬��
	3�������˳�״̬��
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
	state��һ��״̬��ʾ����
	0������״̬��
	1�����ڽ���״̬��
	2������״̬��
	3�������˳�״̬��
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