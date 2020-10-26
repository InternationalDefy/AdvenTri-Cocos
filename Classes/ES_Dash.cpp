#include "Ref2EnemyState.h"

using namespace cocos2d;

CREATE_ENEMYSTATE(ES_Dash);

void ES_Dash::enterFrom(M_EnemyState* stateFrom)
{
	getOwner()->getPhysicsBody()->setVelocityLimit(1400.0f);
	getOwner()->dash();
}
/*
该函数仅有内部exit函数设置好新的stateTo之后调用
同时具有对自身的内存释放操作。
*/
void ES_Dash::exitTo(M_EnemyState* stateTo)
{
	//run a standred end animation or sth?
	//maybe some logic update like
	getOwner()->getPhysicsBody()->setVelocityLimit(700.0f);
	getOwner()->setState(stateTo);
}
void ES_Dash::initState()
{
	_state = AdvenTriEnum::EnemyState::E_STATE_DASH;
	setClockTime(0);
	setLimitTime(10.0f);
	count = 0;
}
void ES_Dash::handleAction(AdvenTriEnum::EnemyAction action)
{
	switch (action)
	{
	case AdvenTriEnum::E_ACTION_DASH:
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
		getOwner()->dashAttack();
		exitToStandred();
		break;
	case AdvenTriEnum::E_ACTION_PARRY:
		getOwner()->parry();
		exitToStandred();
		break;
	case AdvenTriEnum::E_ACTION_HURT:
		onHurt();
		exitToStandred();
		break;
	default:
		break;
	}
}
void ES_Dash::updateMethod(float dt)
{
	count += dt;
	if (count > 0.1f)
	{
		auto sp = Sprite::create("TriAngle.png");
		sp->setPosition(getOwner()->getPosition());
		sp->setColor(Color3B(255, 0, 0));
		sp->setOpacity(128);
		sp->runAction(FadeOut::create(0.1f));
		sp->setRotation(getOwner()->getRotation());
		getOwner()->getParent()->addChild(sp, 0);
		count = 0;
		return;
	}
	return;
}
void ES_Dash::onHurt()
{
	if (getOwner()->isHurting())
	{
		return;
	}
	getOwner()->doHurt();
}