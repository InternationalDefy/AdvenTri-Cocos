#include "Ref2EnemyState.h"

using namespace cocos2d;

CREATE_ENEMYSTATE(ES_Standred);

void ES_Standred::enterFrom(M_EnemyState* stateFrom)
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
void ES_Standred::exitTo(M_EnemyState* stateTo)
{
	//run a standred end animation or sth?
	getOwner()->setState(stateTo);
}
void ES_Standred::initState()
{
	_state = AdvenTriEnum::EnemyState::E_STATE_STANDRED;
	setClockTime(0);
	setLimitTime(FLT_MAX);
}
void ES_Standred::handleAction(AdvenTriEnum::EnemyAction action)
{
	switch (action)
	{
	case AdvenTriEnum::E_ACTION_DASH:
		exitToDash();
		break;
	case AdvenTriEnum::E_ACTION_SKILL1:
		exitToGather(1);
		break;
	case AdvenTriEnum::E_ACTION_SKILL2:
		exitToGather(2);
		break;
	case AdvenTriEnum::E_ACTION_SKILL3:
		exitToGather(3);
		break;
	case AdvenTriEnum::E_ACTION_SKILL4:
		exitToGather(4);
		break;
	case AdvenTriEnum::E_ACTION_ATTACK:
		getOwner()->attack();
		break;
	case AdvenTriEnum::E_ACTION_PARRY:
		getOwner()->parry();
		break;
	case AdvenTriEnum::E_ACTION_HURT:
		onHurt();
		break;
	default:
		break;
	}
}
void ES_Standred::updateMethod(float dt)
{
}
void ES_Standred::parryOnState()
{
	getOwner()->parry();
}
void ES_Standred::onHurt()
{
	if (getOwner()->isHurting())
	{
		return;
	}
	getOwner()->doHurt();
}