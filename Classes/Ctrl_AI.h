#ifndef __CONTROLLER_AI_H__	
#define __CONTROLLER_AI_H__

#include "Ctrl_Base.h"
using namespace cocos2d;

class Ctrl_AI	: public Ctrl_Base
{
protected:
	float fDelayCount;
	float fLimitTime;
	bool	 bCursed;
	bool bFrozen;
	Node* ptnEnemy;
public:
	Ctrl_AI::Ctrl_AI();
	virtual void initWithSD(SD_Ctrl* controllerStringData) override;
	virtual void update(float dt) override;
	CREATE_FUNC_CONTROLLER(Ctrl_AI);
	/*
	此函数处理checkActive操作 和 时间控制操作，返回值表示是否进行动作。
	*/
	bool updateTime(float dt);

public:
	Node* getEnemeyTarget();
	/*
	以下这些类实现于本类中，用于子类使用。
	*/
	void setFrozen() override;
	/*
	curse的正确实现方法是一个RandomNodeTarget，需要和场景类结合，目前未实现。
	*/
	void setCursed() override;
	void setUnFrozen() override;
	void setUnCursed() override;
	virtual Vec2 getDashVec2();
	virtual Vec2 getTargetVec2();
};

#endif