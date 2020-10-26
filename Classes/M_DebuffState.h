#ifndef __M_DEBUFFSTATE__
#define __M_DEBUFFSTATE__

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

class Entity;

class M_DebuffState :public Node
{
	friend class Entity;
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
	int _stateTag;
private:
	float _clockTime;
	float _limitTime;
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
public:
	virtual void enterFrom(M_PlayerState* stateFrom);
	virtual void exitTo(M_PlayerState* stateTo);
public:
	M_PlayerState* create();
public:
	void update(float dt);
	virtual void updateMethod(float dt);
	virtual void initState();
	virtual void handleAction(AdvenTriEnum::PlayerAction action);
};

#endif