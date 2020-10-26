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
	每一步之后的停顿时间
	*/
	float _delay;
	float _count;
	/*
	stepNow是一个表示当前步数的参数
	*/
	int _stepNow = 0;
	Vector<Action*> _steps;
//以下部分处理判断ActionRunning的问题。
private:
	bool _isActionRunning;
public:
	void EntityRunEndCallback()
	{
		_isActionRunning = FALSE;
	}
	//构造函数相关
private:
	int _typeTemp;
	Action* _actionTemp;
	static int ParseStringToType(const std::string& stringOnGo);
	/*
	ParseItemToSteps函数可将stringdata中的item变为Action* step[i]存储
	对码表如下
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
	//实时动作	
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
	每一步之后的停顿时间
	*/
	float getDelay()
	{
		return _delay;
	}
	
};

#endif