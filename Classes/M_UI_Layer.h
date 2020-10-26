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
	Map<std::string, M_Dialogue*> _dialogueMap;//_dialogue��addChild�ˣ�Vect��Map�ǲ�ͬ�ķ����ҵ���ͬ��Dialogue��û�б�addChild
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
	Vector<UI_Menu*> _openMenu; //openMenu��addchild�ˣ�menusû�С�
private:
	void instanceOpenMenu(UI_Menu*);
	void instanceQuitMenu(UI_Menu*);
	//uilayer�ڴ���ʱ�����е�menuװ��Map�е��ǲ���addChildֻretain����������Ҫʹ�õ�ʱ����ִ��addChild������
	//������Ԥ���أ�����ʱ�任����Ч�ʡ�
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
	//��ʵ��㹵ͨ����
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
	//public:ʵ��㹵ͨ����/
	/*void entityAction(FiniteTimeAction*, Entity*, float duration)
	{
	_layerActionScheduler = 0; _layerActionLimit = duration; _layerActionRunning = true; if (layerIsPaused) layer->resume(); (getPausedAgainAfterActionTime);
	}*/
	//*pause->��ֱ������pause����������ʹ��Scheduler��Action���Լ�PhysicsWorld�ķ�����ͣ������ֱ��ʹ��pause�������д���֤��
	//void update(float dt);
	//{updatePosition(dt); ++updateScheduleLimit(dt); etc...}
public:
	//�����ð�ť�ص�
private:
	M_Dialogue* mk17;
	UI_Menu* m;
public:
	void menuCloseCallback(cocos2d::Ref* pSender);

};

#endif