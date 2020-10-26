#ifndef __M_ENEMYSTATE__
#define __M_ENEMYSTATE__

#include "cocos2d.h"
#include "Ref_Enum.h"

#define CREATE_ENEMYSTATE(__TYPE__) \
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

class M_Enemy;

class M_EnemyState :public Node
{
	friend class M_Enemy;
	/*
	private:
	Action* _clockAction;
	public:
	void setClockAction(Action* action);
	Action* getClockAction();
	*/
public:
	//StageTag������ʾ���������࣬��������ı������ָ�����������
	//��InintState������
	AdvenTriEnum::EnemyState _state;
private:
	float _clockTime;
	float _limitTime;
	M_Enemy* _owner;
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
	M_Enemy* getOwner();
	void setOwner(M_Enemy* enemy);
public:
	virtual void enterFrom(M_EnemyState* stateFrom);
	//exitTo ��ֱ��ִ��Exit�Ĳ��������������״̬�����ú;�״̬��ɾ����
	virtual void exitTo(M_EnemyState* stateTo);
	virtual void exitToUse();
	virtual void exitToGather(int type);
	virtual void exitToDash();
	virtual void exitToOperate();
	virtual void exitToStandred();
public:
	M_EnemyState* create();
public:
	void CALLBACK updateFar(float dt);
	virtual void updateMethod(float dt);
	virtual void initState();
	virtual void handleAction(AdvenTriEnum::EnemyAction action);
};

#endif