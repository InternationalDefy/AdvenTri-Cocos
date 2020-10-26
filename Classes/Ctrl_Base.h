#ifndef __CONTROLLER_H__	
#define __CONTROLLER_H__

#include "cocos2d.h"

#define CREATE_FUNC_CONTROLLER(__CTRL__) \
static __CTRL__* __CTRL__::create(SD_Ctrl* controllerStringData) \
{ \
	__CTRL__ *controller = new (std::nothrow) __CTRL__(); \
 	if (controller) \
 	{ \
 		controller->autorelease(); \
 		controller->initWithSD(controllerStringData); \
 		return controller; \
	} \
	CC_SAFE_DELETE(controller); \
	return nullptr; \
 } \

class SD_Ctrl;

class Entity;

using namespace cocos2d;

class Ctrl_Base	: public Node
{
private:
	Entity* _entity;
	bool _actived;
//	Vector<Action*> _steps;
public:
	CREATE_FUNC_CONTROLLER(Ctrl_Base);
	Ctrl_Base::Ctrl_Base();
	//获取实体操作（子类使用）
	Entity* getEntity();
	void setEntity(Entity* entity);
	//控制控制器是否活动的操作（子类使用）
	void active();
	void deActive();
	bool isActive();
public:
	//（子类实现）
	//更新初始化操作
	virtual void initWithSD(SD_Ctrl* controllerStringData);
	/*
	控制器更新操作 
	*/
	virtual void update(float dt);
	//（子类选择性实现）
public:	
	//以下操作是为游戏逻辑而服务的，选择性实现的虚函数。
	virtual void setFrozen();
	virtual void setCursed();
	virtual void setUnFrozen();
	virtual void setUnCursed();
	virtual void assignListener();
	virtual Vec2 getDashVec2();
	virtual Vec2 getTargetVec2();

};

#endif