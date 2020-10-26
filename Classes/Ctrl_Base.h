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
	//��ȡʵ�����������ʹ�ã�
	Entity* getEntity();
	void setEntity(Entity* entity);
	//���ƿ������Ƿ��Ĳ���������ʹ�ã�
	void active();
	void deActive();
	bool isActive();
public:
	//������ʵ�֣�
	//���³�ʼ������
	virtual void initWithSD(SD_Ctrl* controllerStringData);
	/*
	���������²��� 
	*/
	virtual void update(float dt);
	//������ѡ����ʵ�֣�
public:	
	//���²�����Ϊ��Ϸ�߼�������ģ�ѡ����ʵ�ֵ��麯����
	virtual void setFrozen();
	virtual void setCursed();
	virtual void setUnFrozen();
	virtual void setUnCursed();
	virtual void assignListener();
	virtual Vec2 getDashVec2();
	virtual Vec2 getTargetVec2();

};

#endif