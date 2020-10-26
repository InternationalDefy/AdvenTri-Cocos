#include "Ref2Player.h"

using namespace cocos2d;

void M_Player::doHurt()
{
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
	_hp -= _onHurtDamage;
	if (_hp < _Maxhp*0.6) setTexture("triangle_mid_hp.png");
	if (_hp < _Maxhp*0.3) setTexture("triangle_low_hp.png");
	if (_hp <= 0) kill(); 
	runAction(Sequence::create(
		FadeTo::create(0.1f, 128), FadeTo::create(0.1f, 255),
		FadeTo::create(0.1f, 128), FadeTo::create(0.1f, 255),
		FadeTo::create(0.1f, 128), FadeTo::create(0.1f, 255),
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
void M_Player::dash()
{
	if (!_skillReady.at("Dash"))
	{
		return;
	}
	activeSkill("Dash");
}
void M_Player::parry()
{
	log("Parry");
}
void M_Player::attack()
{
	if (!_skillReady.at("SimpleAttack"))
	{
		return;
	}
	activeSkill("SimpleAttack");
}
void M_Player::useItem()
{
	log("UseFuncFrom item*");
	log("Update Number");
	log("Play use Animation");
}
void M_Player::changeItem()
{
	log("ItemChange");
}
void M_Player::dropItem()
{
	log("DropItem");
}
void M_Player::operate()
{
	log("Operate!");
}