#ifndef __ES_DASH__
#define __ES_DASH__

#include "cocos2d.h"
#include "Ref_Enum.h"

using namespace cocos2d;

class M_Enemy;
class M_EnemyState;

class ES_Dash :public M_EnemyState
{
	friend class M_Enemy;
private:
	void onHurt();
public:
	void enterFrom(M_EnemyState* stateFrom);//override
	void exitTo(M_EnemyState* stateTo);//override
public:
	static ES_Dash* create();
public:
	void updateMethod(float dt);
	void initState(); //override
	void handleAction(AdvenTriEnum::EnemyAction action);//override
private:
	float count;
};

#endif