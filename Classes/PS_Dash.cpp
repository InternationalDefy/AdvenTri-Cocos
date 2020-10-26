#include "Ref2PlayerState.h"

using namespace cocos2d;

CREATE_PLAYERSTATE(PS_Dash);

void PS_Dash::enterFrom(M_PlayerState* stateFrom)
{
	getPlayer()->getPhysicsBody()->setVelocityLimit(1400.0f);
	getPlayer()->dash();
}
/*
该函数仅有内部exit函数设置好新的stateTo之后调用
同时具有对自身的内存释放操作。
*/
void PS_Dash::exitTo(M_PlayerState* stateTo)
{
	//run a standred end animation or sth?
	//maybe some logic update like
	getPlayer()->getPhysicsBody()->setVelocityLimit(700.0f);
	getPlayer()->setState(stateTo);
}
void PS_Dash::initState()
{
	_state = AdvenTriEnum::PlayerStateType::P_STATE_DASH;
	setClockTime(0);
	setLimitTime(10.0f);
	count = 0;
}
void PS_Dash::handleAction(AdvenTriEnum::PlayerAction action)
{
	switch (action)
	{
	case AdvenTriEnum::P_ACTION_DASH:
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
		if (getPlayer()->isSkillReady("DashAttack"))
		{
			getPlayer()->dashAttack();
			exitToStandred();
		}
		break;
	case AdvenTriEnum::P_ACTION_PARRY:
		if (getPlayer()->isSkillReady("Parry"))
		{
			getPlayer()->parry();
			exitToStandred();
		}
		break;
	case AdvenTriEnum::P_ACTION_BLINK:
		if (getPlayer()->canBlink()) getPlayer()->blink();
		break;
	case AdvenTriEnum::P_ACTION_HURT:
		onHurt();
		exitToStandred();
		break;
	default:
		break;
	}
}
void PS_Dash::updateMethod(float dt)
{
	count += dt;
	if (count > 0.1f)
	{
		auto sp = Sprite::create("TriAngle.png");
		sp->setPosition(getPlayer()->getPosition());
		sp->setColor(Color3B(128, 128, 196));
		sp->setOpacity(128);
		sp->runAction(FadeOut::create(0.1f));
		sp->setRotation(getPlayer()->getRotation());
		getPlayer()->getParent()->addChild(sp, 0);
		count = 0;
		return;
	}
	return;
}
void PS_Dash::parryOnState()
{
}
void PS_Dash::onHurt()
{
	if (getPlayer()->isHurting())
	{
		return;
	}
	getPlayer()->doHurt();
}
void PS_Dash::hurtEndingCallback()
{
}