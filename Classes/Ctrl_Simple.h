#ifndef __CONTROLLER_SIMPLE_H__	
#define __CONTROLLER_SIMPLE_H__

#include "Ctrl_Base.h"

using namespace cocos2d;

class Entity;
class SD_Item;

class 	Ctrl_Simple : public Ctrl_Base
{
private:
	/**
	ÿһ��֮���ͣ��ʱ��
	*/
	float _delay;
	float _count;
	/*
	stepNow��һ����ʾ��ǰ�����Ĳ���
	*/
	int _stepNow = 0;
	Vector<Action*> _steps;
//���²��ִ����ж�ActionRunning�����⡣
private:
	bool _isActionRunning;
public:
	void EntityRunEndCallback()
	{
		_isActionRunning = FALSE;
	}
	//���캯�����
private:
	int _typeTemp;
	Action* _actionTemp;
	static int ParseStringToType(const std::string& stringOnGo);
	/*
	ParseItemToSteps�����ɽ�stringdata�е�item��ΪAction* step[i]�洢
	���������
	Wait:0;
	MoveTo:1;
	MoveBy:2;
	Attack:3;?
	Speak:4;?
	Skill?
	*/
	static void ParseItemToSteps(Ctrl_Simple* Ctrl, SD_Item* item);
public:
	CREATE_FUNC_CONTROLLER(Ctrl_Simple);
	
public:
	void initWithSD(SD_Ctrl* controllerData);
	//ʵʱ����	
public:
	void update(float dt);
private:
	void move();
	//getters&setters
public:
	void setDelay(float x)
	{
		_delay = x;
	}
	/**
	ÿһ��֮���ͣ��ʱ��
	*/
	float getDelay()
	{
		return _delay;
	}
	
};

#endif