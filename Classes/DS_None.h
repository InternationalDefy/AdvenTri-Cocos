#ifndef __PS_STANDRED__
#define __PS_STANDRED__

#include "cocos2d.h"
#include "Ref_Enum.h"

#define HURT_TIME 3.0f

using namespace cocos2d;

class M_Player;
class M_PlayerState;

class PS_Standred :public M_PlayerState
{
private:
	//һϵ�в���������ǰ�����������ͬ����ʱ��Ҫ�Ĳ�����
	void exitToUse();
	void exitToGather(int type);
	void exitToDash();
	void exitToOperate();
	void parryOnState();
	void onHurt();
private:
	void hurtEndingCallback();
public:
	void enterFrom(M_PlayerState* stateFrom);//override
	void exitTo(M_PlayerState* stateTo);//override
public:
	static PS_Standred* create();
public:
	void updateMethod(float dt);
	void initState(); //override
	void handleAction(AdvenTriEnum::PlayerAction action);//override
};

#endif