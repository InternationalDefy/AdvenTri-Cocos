#include "Ref2Enemy.h"

USING_NS_CC;

void M_Enemy::activeSkill(const std::string& name)
{
	_skills.at(name)->active();
}
void M_Enemy::doHurt()
{
	_onHurtDamage = M_Amor::handleDamageNum(_amor, _onHurtType, _onHurtDamage);
	_onDebuffLimit = M_Amor::handleDebuffDuration(_amor, _onHurtType, _onDebuffLimit);

	switch (_onHurtType)
	{
	case AdvenTriEnum::D_TYPE_BURN:
		handleDebuffEnter(AdvenTriEnum::Debuff::DBUFF_FIRE);
		break;
	case AdvenTriEnum::D_TYPE_ICY:
		handleDebuffEnter(AdvenTriEnum::Debuff::DBUFF_FROST);
		break;
	case AdvenTriEnum::D_TYPE_POISONED:
		handleDebuffEnter(AdvenTriEnum::Debuff::DBUFF_POISON);
		break;
	case AdvenTriEnum::D_TYPE_BLED:
		handleDebuffEnter(AdvenTriEnum::Debuff::DBUFF_BLEED);
		break;
	case AdvenTriEnum::D_TYPE_SHOCK:
		handleDebuffEnter(AdvenTriEnum::Debuff::DBUFF_SHOCK);
		break;
	case AdvenTriEnum::D_TYPE_CURSE:
		handleDebuffEnter(AdvenTriEnum::Debuff::DBUFF_CURSE);
		break;
	default:
		break;
	}
	//do Something With Amor using Type;
	_hp -= _onHurtDamage;
	runAction(Sequence::create(
		FadeTo::create(0.1f, 128), FadeTo::create(0.1f, 255),
		FadeTo::create(0.1f, 128), FadeTo::create(0.1f, 255),
		NULL));
	_hurting = true;
	_hurtingTime = 0;
	/*
	也许Effect应当在物理监听处处理？这样可以使位置更准确。
	log("Effect!");
	log("PlayAnimation!");
	*/
}
void M_Enemy::updateHurtingTime(float dt)
{
	if (!_hurting)
	{
		return;
	}
	_hurtingTime += dt;
	if (_hurtingTime > HURT_TIME)
	{
		_hurting = false;
		return;
	}
}