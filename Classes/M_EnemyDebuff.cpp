#include "Ref2Enemy.h"

USING_NS_CC;

void M_Enemy::handleDebuffEnter(AdvenTriEnum::Debuff debuff)
{
	/*
	该操作包含
	0.处理特殊情况
	1.Animation 的更新
	2.状态和时间的重设
	这个switch语句只处理不同的情况
	*/
	switch (debuff)
	{
	case AdvenTriEnum::DBUFF_FIRE:
		if (_onDebuff.at(AdvenTriEnum::DBUFF_FROST))
		{
			handleDebuffOut(AdvenTriEnum::Debuff::DBUFF_FIRE, AdvenTriEnum::Debuff::DBUFF_FROST);
			return;
		}
		break;
	case AdvenTriEnum::DBUFF_FROST:
		if (_onDebuff.at(AdvenTriEnum::DBUFF_FIRE))
		{
			handleDebuffOut(AdvenTriEnum::Debuff::DBUFF_FIRE, AdvenTriEnum::Debuff::DBUFF_FROST);
			return;
		}
		getController()->setFrozen();
		break;
	case AdvenTriEnum::DBUFF_PARRYED:
		break;
	case AdvenTriEnum::DBUFF_POISON:
		break;
	case AdvenTriEnum::DBUFF_CURSE:
		if (_onDebuff.at(AdvenTriEnum::DBUFF_SHOCK))
		{
			handleDebuffOut(AdvenTriEnum::Debuff::DBUFF_CURSE, AdvenTriEnum::Debuff::DBUFF_SHOCK);
			return;
		}
		getController()->setCursed();
		break;
	case AdvenTriEnum::DBUFF_SHOCK:
		if (_onDebuff.at(AdvenTriEnum::DBUFF_CURSE))
		{
			handleDebuffOut(AdvenTriEnum::Debuff::DBUFF_CURSE, AdvenTriEnum::Debuff::DBUFF_SHOCK);
			return;
		}
		break;
	case AdvenTriEnum::DBUFF_BLEED:
		break;
	default:
		break;
	}
	//_debuffNode->runAction(_animaiton.at(debuff));
	/*
	if (!_onDebuffLimit > 0.1f)
	{
		_amor->deActiveAnimate(debuff);
		_amor->activeAnimate(debuff);
	}
	*/
	_onDebuff.at(debuff) = true;
	_debuffTime.at(debuff) = 0;
	_debuffCount.at(debuff) = 0;
	_debuffLimit.at(debuff) = _onDebuffLimit;
	_onDebuffLimit = 0;
}
void M_Enemy::handleDebuffEffect(AdvenTriEnum::Debuff debuff)
{
	switch (debuff)
	{
	case AdvenTriEnum::DBUFF_FIRE:
		setHurtDamage(1);
		setHurtType(AdvenTriEnum::DamageType::D_TYPE_FIRE);
		doHurt();
		break;
	case AdvenTriEnum::DBUFF_FROST:
		break;
	case AdvenTriEnum::DBUFF_PARRYED:
		break;
	case AdvenTriEnum::DBUFF_POISON:
		setHurtDamage(1);
		setHurtType(AdvenTriEnum::DamageType::D_TYPE_POISON);
		doHurt();
		break;
	case AdvenTriEnum::DBUFF_CURSE:
		break;
	case AdvenTriEnum::DBUFF_SHOCK:
		getPhysicsBody()->setVelocity(Vec2(0, 0));
		//_debuffNode->runAction("ShockAnimate");
		break;
	case AdvenTriEnum::DBUFF_BLEED:
		setHurtDamage(1);
		setHurtType(AdvenTriEnum::DamageType::D_TYPE_BLADE);
		doHurt();
		break;
	default:
		break;
	}
}
void M_Enemy::handleDebuffOut(AdvenTriEnum::Debuff debuff)
{
	auto k = Animate::create(Animation::create());
	switch (debuff)
	{
	case AdvenTriEnum::DBUFF_FIRE:
		break;
	case AdvenTriEnum::DBUFF_FROST:
		//联系存档系统和实体状态，设置回正确的Ctrl_Base
		getController()->setUnFrozen();
		break;
	case AdvenTriEnum::DBUFF_PARRYED:
		break;
	case AdvenTriEnum::DBUFF_POISON:
		break;
	case AdvenTriEnum::DBUFF_CURSE:
		getController()->setUnCursed();
		break;
	case AdvenTriEnum::DBUFF_SHOCK:
		break;
	case AdvenTriEnum::DBUFF_BLEED:
		break;
	default:
		break;
	}
	//_debuffNode->runanimation(debuff);
	/*
	_amor->deactiveAnimation
	_amor>activeAnimation(Out Debuff)
	*/
	_onDebuff.at(debuff) = false;
}
void M_Enemy::handleDebuffOut(AdvenTriEnum::Debuff d1, AdvenTriEnum::Debuff d2)
{
	if (d1 == AdvenTriEnum::Debuff::DBUFF_FIRE&&d2 == AdvenTriEnum::Debuff::DBUFF_FROST
		|| d2 == AdvenTriEnum::Debuff::DBUFF_FIRE&&d1 == AdvenTriEnum::Debuff::DBUFF_FROST)
	{
		_onDebuff.at(d1) = false;
		_onDebuff.at(d2) = false;
		getController()->setUnFrozen();
		//_debuffNode->runAnimation(XXX);
		return;
	}
	if (d1 == AdvenTriEnum::Debuff::DBUFF_CURSE&&d2 == AdvenTriEnum::Debuff::DBUFF_SHOCK
		|| d2 == AdvenTriEnum::Debuff::DBUFF_CURSE&&d1 == AdvenTriEnum::Debuff::DBUFF_SHOCK)
	{
		_onDebuff.at(d1) = false;
		_onDebuff.at(d2) = false;
		getController()->setUnCursed();
		//_debuffNode->runAnimation(XXX);
		return;
	}
}

void M_Enemy::updateDebuffTime(AdvenTriEnum::Debuff name, float dt)
{
	_debuffTime.at(name) += dt;
	_debuffCount.at(name) += dt;
	if (_debuffCount.at(name) >= 1)
	{
		handleDebuffEffect(name);
		_debuffCount.at(name) = 0;
	}
	if (_debuffTime.at(name) >= _debuffLimit.at(name))
	{
		_debuffTime.at(name) = 0;
		handleDebuffOut(name);
		return;
	}
}