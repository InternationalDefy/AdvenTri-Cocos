#include "Ref2PlayerState.h"

using namespace cocos2d;

CREATE_PLAYERSTATE(PS_Standred);

void PS_Standred::enterFrom(M_PlayerState* stateFrom)
{
 	switch (stateFrom->_state)
	{
	case AdvenTriEnum::PlayerStateType::P_STATE_DASH:
		break;
	default:
		break;
	}
}
/*
该函数仅有内部exit函数设置好新的stateTo之后调用
同时具有对自身的内存释放操作。
*/
void PS_Standred::exitTo(M_PlayerState* stateTo)
{
	//run a standred end animation or sth?
	getPlayer()->setState(stateTo);
}
void PS_Standred::initState()
{
	_state = AdvenTriEnum::PlayerStateType::P_STATE_STANDRED;
	setClockTime(0);
	setLimitTime(FLT_MAX);
}
void PS_Standred::handleAction(AdvenTriEnum::PlayerAction action)
{
	switch (action)
	{
	case AdvenTriEnum::P_ACTION_DASH:
		if (getPlayer()->isSkillReady("Dash")) exitToDash();
		break;
	case AdvenTriEnum::P_ACTION_SKILL1:
		if (getPlayer()->isSkillReady("Skill1")) exitToGather(1);
		break;
	case AdvenTriEnum::P_ACTION_SKILL2:
		if (getPlayer()->isSkillReady("Skill2")) exitToGather(2);
		break;
	case AdvenTriEnum::P_ACTION_OPERATE:
		if (getPlayer()->canOperate()) exitToOperate();
		break;
	case AdvenTriEnum::P_ACITON_USEITEM:
		if (getPlayer()->canUseItem()) exitToUse();
		break;
	case AdvenTriEnum::P_ACTION_CHANGEITEM:
		getPlayer()->changeItem();
		break;
	case AdvenTriEnum::P_ACTION_DROPITEM:
		getPlayer()->dropItem();
		break;
	case AdvenTriEnum::P_ACTION_ATTACK:
		if (!getPlayer()->isSkillReady("SimpleAttack"))
			getPlayer()->attack();
		break;
	case AdvenTriEnum::P_ACTION_PARRY:
		if (getPlayer()->isSkillReady("Parry")) getPlayer()->parry();
		break;
	case AdvenTriEnum::P_ACTION_BLINK:
		if (getPlayer()->canBlink()) getPlayer()->blink();
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
void PS_Standred::parryOnState()
{
	getPlayer()->parry();
}
void PS_Standred::onHurt()
{
	if (getPlayer()->isHurting())
	{
		return;
	}
	getPlayer()->doHurt();
}