#ifndef __PS_DASH__
#define __PS_DASH__

#include "cocos2d.h"
#include "Ref_Enum.h"

using namespace cocos2d;

class M_Player;
class M_PlayerState;

class PS_Dash :public M_PlayerState
{
	friend class M_Player;
private:
	void parryOnState();
	void onHurt();
private:
	void hurtEndingCallback();
public:
	void enterFrom(M_PlayerState* stateFrom);//override
	void exitTo(M_PlayerState* stateTo);//override
public:
	static PS_Dash* create();
public:
	void updateMethod(float dt);
	void initState(); //override
	void handleAction(AdvenTriEnum::PlayerAction action);//override
private:
	float count;
};

#endif