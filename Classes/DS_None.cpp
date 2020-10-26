#include "Ref2PlayerState.h"

using namespace cocos2d;

CREATE_PLAYERSTATE(PS_Standred);

void PS_Standred::enterFrom(M_PlayerState* stateFrom)
{
}
/*
该函数仅有内部exit函数设置好新的stateTo之后调用
同时具有对自身的内存释放操作。
*/
void PS_Standred::exitTo(M_PlayerState* stateTo)
{
}
void PS_Standred::initState()
{
	_stateTag = 1;
	setClockTime(0);
	setLimitTime(FLT_MAX);
}
void PS_Standred::handleAction(AdvenTriEnum::PlayerAction action)
{
	switch (action)
	{
	case AdvenTriEnum::P_ACTION_DASH:
		exitToDash();
		break;
	case AdvenTriEnum::P_ACTION_SKILL1:
		//if (!_CollDown&&haveEnegy())
		exitToGather(1);
		break;
	case AdvenTriEnum::P_ACTION_SKILL2:
		//if (!_CollDown&&haveEnegy())
		exitToGather(2);
		break;
	case AdvenTriEnum::P_ACTION_OPERATE:
		exitToOperate();
		break;
	case AdvenTriEnum::P_ACITON_USEITEM:
		exitToUse();
		break;
	case AdvenTriEnum::P_ACTION_CHANGEITEM:
		//getPlayer()->changeItem();
		break;
	case AdvenTriEnum::P_ACTION_DROPITEM:
		//getPlayer()->dropItem();
		break;
	case AdvenTriEnum::P_ACTION_ATTACK:
		//if (!_CollDown)
		getPlayer()->attack();
		break;
	case AdvenTriEnum::P_ACTION_PARRY:
		//if (!cooldown)
		//getPlayer()->parry();
		break;
	case AdvenTriEnum::P_ACTION_BLINK:
		//if (!cooldown)
		//getPlayer()->blink();
		break;
	case AdvenTriEnum::P_ACTION_HURT:
		onHurt();
		break;
	default:
		break;
	}
}
void PS_Standred::updateMethod(float dt)
{
}
void PS_Standred::exitToUse()
{
}
void PS_Standred::exitToGather(int type)
{
}
void PS_Standred::exitToDash()
{
}
void PS_Standred::exitToOperate()
{
}
void PS_Standred::parryOnState()
{
}
void PS_Standred::onHurt()
{
	//getPlayer()->hurt();
}
void PS_Standred::hurtEndingCallback()
{
}