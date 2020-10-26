#ifndef __M_GAMELAYER_BASE__
#define __M_GAMELAYER_BASE__

#include "cocos2d.h"
using namespace cocos2d;

class SD_GameLayer;
class Sys_Scene;
class M_Enemy;
class M_Player;
class UI_Layer;
class Test_Layer;
class Ctrl_Camera;
class Ctrl_Player;

class M_GameLayer :public Layer
{
public:
	M_GameLayer();
public:
	bool _isPaused;
	
	UI_Layer* uiLayer;

	Ctrl_Camera* cameraCtrl;
	Ctrl_Player* playerCtrl;

	Node* cameraBorder;
	Node* physicsBorder;
	M_Player* player;
	Vector<M_Enemy*> enmey;

	friend class Test_Layer;

public:
	virtual bool initBorder(SD_GameLayer*);

	virtual bool initNpc(SD_GameLayer*);
	virtual bool initEnemy(SD_GameLayer*);
	/*
	�˺���Ϊ�ó������Player*
	����ʵ���ϲ���ʹ��SD_GameLayer
	*/
	virtual bool initPlayer();
	virtual bool initBackground(SD_GameLayer*);

	virtual bool initPhysicsEvent(SD_GameLayer*);
	virtual bool initEventDispatcher(SD_GameLayer*);
public:
	static Scene* getScene(SD_GameLayer*);
	static M_GameLayer* create(SD_GameLayer*);
	//init��һ�ּ����Բ�������������������ʵ�壬�߽磬�¼������ȵ�init���䴦����Ϸ����������ˡ�
	virtual bool init(SD_GameLayer*);
public:
	//�����update�����������κ�ʵ�������ϵ����飬ָ�ṩһ���ɹ����ʵĽӿڡ�
	virtual void update(float dt);
public:
	//�浵ϵͳ��صı�ʶ���൱��Ҫ
	std::string GameLayerTag;
	std::map<std::string, int> EntityState;
public:
	Node* getLayer(){ return this; }
	const Node* getLayer()const{ return this; }

public:
	static M_GameLayer* create();
	//���·���ּ�ڴ���һ��ֻ��Ĭ�����ԵĿճ���GameLayer�࣬�ڲ�����ϵ��ʹ�á�
	//���·�������������ֱ���޸���ӳ������ݵĺ������ڲ�����ϵ��ʹ�á�
	//ʹ�ð�����ʹ�ÿճ�����Ӳ���Ҫ�أ�ʹ�����г���*ɾ*�Ĳ���Ҫ�ء�
	void tFuncAddEnemy(const std::string& name,Vec3 pos,int localZOrder,const std::string& tag);
	void tFuncAddNpc(const std::string& name,Vec3 pos,int localZOrder,const std::string& tag);
	//Playerֻ����������Ӳ������������Կ���get֮�����á�
	void tFuncAddPlayer(int localZOrder, const std::string& sznPlayerCtrl, const std::string& sznPlayerPhysicsBody);
	M_Player* tFuncGetPlayer();
	//����Ĳ�����һ���ļ�������������ļ��еĶ���������Border
	void tFuncSetBorder(const std::string& snBorderFile);
	//BG�Ĵ�������Border��ͬ�����ҵ���StringΪName��Ӧ��SD�����BG��ԭ����BG̫�����ӣ���������ɱ��ߡ�
	void tFuncSetBackground(const std::string& sdnBackground);
	void tFuncInitPhysicsEvent();
	void tFuncInitEventDispatcher(const std::string& snListenerSet);
};

#endif