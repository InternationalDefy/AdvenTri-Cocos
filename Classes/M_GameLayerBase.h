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
	此函数为该场景添加Player*
	但是实际上并不使用SD_GameLayer
	*/
	virtual bool initPlayer();
	virtual bool initBackground(SD_GameLayer*);

	virtual bool initPhysicsEvent(SD_GameLayer*);
	virtual bool initEventDispatcher(SD_GameLayer*);
public:
	static Scene* getScene(SD_GameLayer*);
	static M_GameLayer* create(SD_GameLayer*);
	//init是一种集合性操作，包括场景背景，实体，边界，事件监听等等init，其处理游戏层的所有事宜。
	virtual bool init(SD_GameLayer*);
public:
	//父类的update函数并不做任何实际意义上的事情，指提供一个可供访问的接口。
	virtual void update(float dt);
public:
	//存档系统相关的标识，相当重要
	std::string GameLayerTag;
	std::map<std::string, int> EntityState;
public:
	Node* getLayer(){ return this; }
	const Node* getLayer()const{ return this; }

public:
	static M_GameLayer* create();
	//以下方法旨在创建一个只有默认属性的空场景GameLayer类，在测试体系中使用。
	//以下方法还包括可以直接修改添加场景内容的函数，在测试体系中使用。
	//使用包括：使用空场景添加测试要素，使用已有场景*删*改测试要素。
	void tFuncAddEnemy(const std::string& name,Vec3 pos,int localZOrder,const std::string& tag);
	void tFuncAddNpc(const std::string& name,Vec3 pos,int localZOrder,const std::string& tag);
	//Player只做基础的添加操作，其余属性可以get之后设置。
	void tFuncAddPlayer(int localZOrder, const std::string& sznPlayerCtrl, const std::string& sznPlayerPhysicsBody);
	M_Player* tFuncGetPlayer();
	//输入的参数是一个文件名，利用这个文件中的定义来设置Border
	void tFuncSetBorder(const std::string& snBorderFile);
	//BG的处理方法与Border不同，是找到改String为Name对应的SD来添加BG，原因是BG太过复杂，单独处理成本高。
	void tFuncSetBackground(const std::string& sdnBackground);
	void tFuncInitPhysicsEvent();
	void tFuncInitEventDispatcher(const std::string& snListenerSet);
};

#endif