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
	�˺�������checkActive���� �� ʱ����Ʋ���������ֵ��ʾ�Ƿ���ж�����
	*/
	bool updateTime(float dt);

public:
	Node* getEnemeyTarget();
	/*
	������Щ��ʵ���ڱ����У���������ʹ�á�
	*/
	void setFrozen() override;
	/*
	curse����ȷʵ�ַ�����һ��RandomNodeTarget����Ҫ�ͳ������ϣ�Ŀǰδʵ�֡�
	*/
	void setCursed() override;
	void setUnFrozen() override;
	void setUnCursed() override;
	virtual Vec2 getDashVec2();
	virtual Vec2 getTargetVec2();
};

#endif