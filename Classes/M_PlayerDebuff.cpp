#include "Ref2Player.h"

using namespace cocos2d;

void M_Player::handleDebuffEnter(AdvenTriEnum::Debuff debuff)
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
		dynamic_cast<Ctrl_Player*> (getpCtrl())->setFrozen();
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
		dynamic_cast<Ctrl_Player*> (getpCtrl())->setCursed();
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
	std::string str = "Debuff_" + (AdvenTriEnum::changeDebuffTypeToString(debuff));
	_debuffNode->runAction(_animationPack->getAnimation(
		str));
	_onDebuff.at(debuff) = true;
	_debuffTime.at(debuff) = 0;
	_debuffCount.at(debuff) = 0;
	_debuffLimit.at(debuff) = _onDebuffLimit;
	_onDebuffLimit = 2.0f;
}
void M_Player::handleDebuffEffect(AdvenTriEnum::Debuff debuff)
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
void M_Player::handleDebuffOut(AdvenTriEnum::Debuff debuff)
{
	auto k = Animate::create(Animation::create());
	switch (debuff)
	{
	case AdvenTriEnum::DBUFF_FIRE:
		break;
	case AdvenTriEnum::DBUFF_FROST:
		//联系存档系统和实体状态，设置回正确的Ctrl_Base
		dynamic_cast<Ctrl_Player*> (getpCtrl())->setUnFrozen();
		break;
	case AdvenTriEnum::DBUFF_PARRYED:
		break;
	case AdvenTriEnum::DBUFF_POISON:
		break;
	case AdvenTriEnum::DBUFF_CURSE:
		dynamic_cast<Ctrl_Player*> (getpCtrl())->setUncursed();
		break;
	case AdvenTriEnum::DBUFF_SHOCK:
		break;
	case AdvenTriEnum::DBUFF_BLEED:
		break;
	default:
		break;
	}
	//_debuffNode->runanimation(debuffOut);
	_onDebuff.at(debuff) = false;
}

void M_Player::handleDebuffOut(AdvenTriEnum::Debuff d1, AdvenTriEnum::Debuff d2)
{
	if (d1 == AdvenTriEnum::Debuff::DBUFF_FIRE&&d2 == AdvenTriEnum::Debuff::DBUFF_FROST
		|| d2 == AdvenTriEnum::Debuff::DBUFF_FIRE&&d1 == AdvenTriEnum::Debuff::DBUFF_FROST)
	{	
		_onDebuff.at(d1) = false;
		_onDebuff.at(d2) = false;
		dynamic_cast<Ctrl_Player*> (getpCtrl())->setUnFrozen();
		//_debuffNode->runAnimation(XXX);
		return;
	}
	if (d1 == AdvenTriEnum::Debuff::DBUFF_CURSE&&d2 == AdvenTriEnum::Debuff::DBUFF_SHOCK
		|| d2 == AdvenTriEnum::Debuff::DBUFF_CURSE&&d1 == AdvenTriEnum::Debuff::DBUFF_SHOCK)
	{
		_onDebuff.at(d1) = false;
		_onDebuff.at(d2) = false;
		dynamic_cast<Ctrl_Player*> (getpCtrl())->setUncursed();
		//_debuffNode->runAnimation(XXX);
		return;
	}
}