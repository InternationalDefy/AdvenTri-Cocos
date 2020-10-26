#ifndef __M_PLAYERSTATE__
#define __M_PLAYERSTATE__

#include "cocos2d.h"
#include "Ref_Enum.h"

#define CREATE_PLAYERSTATE(__TYPE__) \
__TYPE__* __TYPE__::create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet&&pRet->init()) \
				    { \
		pRet->autorelease(); \
		pRet->initState(); \
        return pRet; \
				    } \
															    else \
															    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
															    } \
} \

using namespace cocos2d;

class M_Player;

class M_PlayerState :public Node
{
	friend class M_Player;
	/*
private:
	Action* _clockAction;
public:
	void setClockAction(Action* action);
	Action* getClockAction();
	*/
public:
	//StageTag用来表示其个体的种类，更加清楚的便于区分各派生类种类
	//在InintState中设置
	AdvenTriEnum::PlayerStateType _state;
private:
	float _clockTime;
	float _limitTime;
	M_Player* _player;
public:
	float getClockTime()
	{
		return _clockTime;
	}
	void setClockTime(float x)
	{
		_clockTime = x;
		return;
	}
	float getLimitTime()
	{
		return _limitTime;
	}
	void setLimitTime(float x)
	{
		_limitTime = x;
		return;
	}
public:
	M_Player* getPlayer();
	void setPlayer(M_Player* player);
public:
	virtual void enterFrom(M_PlayerState* stateFrom);
	//exitTo 是直接执行Exit的操作，里面包括新状态的设置和旧状态的删除。
	virtual void exitTo(M_PlayerState* stateTo);
	virtual void exitToUse();
	virtual void exitToGather(int type);
	virtual void exitToDash();
	virtual void exitToOperate();
	virtual void exitToStandred();
public:
	M_PlayerState* create();
public:
	void CALLBACK updateFar(float dt);
	virtual void updateMethod(float dt);
	virtual void initState();
	virtual void handleAction(AdvenTriEnum::PlayerAction action);
};

#endif