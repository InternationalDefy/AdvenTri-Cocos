#ifndef __ES_STANDRED__
#define __ES_STANDRED__

#include "cocos2d.h"
#include "Ref_Enum.h"

//#define HURT_TIME 3.0f

using namespace cocos2d;

class M_Enemy;
class M_EnemyState;

class ES_Standred :public M_EnemyState
{
	friend class M_Enemy;
private:
	//一系列操作，处理当前情况下遇见不同问题时需要的操作。
	void parryOnState();
	void onHurt();
public:
	void enterFrom(M_EnemyState* stateFrom);//override
	void exitTo(M_EnemyState* stateTo);//override
public:
	static ES_Standred* create();
public:
	void updateMethod(float dt);
	void initState(); //override
	void handleAction(AdvenTriEnum::EnemyAction action); //override
};

#endif