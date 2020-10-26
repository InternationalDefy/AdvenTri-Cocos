#include "Ref2Player.h"

using namespace cocos2d;
//可能牵扯到游戏结束操作
void M_Player::destroy(){}
//初始化操作
M_Player* M_Player::create(const std::string& filename)
{
	M_Player *player = new (std::nothrow) M_Player();
	if (player && player->initWithFile(filename))
	{
		//entity->setActionRunning(false);
		player->initData();
		player->initEntity();
		player->autorelease();
		return player;
	}
	CC_SAFE_DELETE(player);
	return nullptr;
}
void M_Player::initData()
{
	setLocalZOrder(0);
	_state = PS_Standred::create();
	_state->setPlayer(this);
	_hurting = false;
	_hurtingTime = 0;
	_debuffNode = Sprite::create(/*"2.png"*/);
	_debuffNode->setOpacity(196);

	//以下，仅在3.29测试Debuff动画时使用。
	_Maxhp = 10;
	_hp = 10;

	//以上

	this->addChild(_debuffNode);
	_debuffNode->setLocalZOrder(1);
	_debuffNode->setPosition(Vec2(58, 50));
	_onDebuffLimit = 0;
	for (auto i = 0; i <= 6;++i)
	{
		AdvenTriEnum::Debuff k = static_cast<AdvenTriEnum::Debuff> (i);
		_onDebuff.insert(std::make_pair(k, false));
		_debuffTime.insert(std::make_pair(k, 0));
		_debuffLimit.insert(std::make_pair(k, DEBUFF_LIMIT));
		_debuffCount.insert(std::make_pair(k, 0));
	}
}
void M_Player::addSkill(const std::string& positionName, M_pSkill* skill)
{
	_skills.insert(positionName, skill);
	_skillReady.insert(std::make_pair(positionName, true));
	_skillCoolDown.insert(std::make_pair(positionName, 0));
	skill->setOwner(this);
}/*
void M_Player::addAnimationPack(M_AnimationPack* animationPack)
{
	_animationPack = animationPack;
}
*/
//基础操作
void M_Player::handleAction(AdvenTriEnum::PlayerAction action)
{
	_state->handleAction(action);
	return;
}
//对是否Ready的检验位于State中，不Ready就不能进入Gathering状态。
void M_Player::activeSkill(const std::string& name)
{
	_skillReady.at(name) = false;
	_skillCoolDown.at(name) = 0;
	_skills.at(name)->active();
	return;
}
/*
void M_Player::activeAnimate(const std::string& key)
{
	auto act = _animationPack->getAnimate(key);
	if (act)
	{
		runAction(act);
		return;
	}
	else
	{
		auto k = "M_Enemy's Animate " + key + " UNFOUD!";
		log(k.c_str());
		return;
	}
}*/

//state操作
void M_Player::setState(M_PlayerState* state)
{
	if (_state)
	{
		state->setPlayer(this);
		state->enterFrom(_state);
		_state = state;
	}
	else
	{
		_state = state;
		state->setPlayer(this);
	}
}

//更新操作
void M_Player::update(float dt)
{
	logicUpdate(dt);
	for (auto i : _children)
	{
		i->update(dt);
	}
	_state->updateFar(dt);
}
void M_Player::logicUpdate(float dt)
{
	for (auto i : _skillReady)
	{
		if (!i.second) updateSkillCooldown(i.first, dt);
	}
	updateHurtingTime(dt);
	for (auto i : _onDebuff)
	{
		if (i.second) updateDebuffTime(i.first, dt);
	}
	/*
	log("Update Skill CoolDown");
	log("Update Parry Time");
	log("Update Hurting Time");
	log("Update XXX");
	*/
}
void M_Player::updateHurtingTime(float dt)
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
void M_Player::updateDebuffTime(AdvenTriEnum::Debuff name, float dt)
{
	_debuffTime.at(name) += dt;
	_debuffCount.at(name) += dt;
	if (_debuffCount.at(name) >= 1)
	{
		handleDebuffEffect(name);
		_debuffCount.at(name) =0;
	}
	if (_debuffTime.at(name) >= _debuffLimit.at(name))
	{
		_debuffTime.at(name) = 0;
		handleDebuffOut(name);
		return;
	}
}
void M_Player::updateSkillCooldown(const std::string& name,float dt)
{
	_skillCoolDown.at(name) += dt;
	if (_skillCoolDown.at(name) >= _skills.at(name)->getCoolDown())
	{
		_skillReady.at(name) = true;
		return;
	}
	return;
}

void M_Player::kill()
{
	std::string str = "Kill_" + AdvenTriEnum::changeDamageTypeToKillString(_onHurtType);
	//runAction(_animationPack->getAnimate(str));
	
	
	//logic something
	//maybe stop ai
	// ui something
	//以下只是在测试动画时使用
	_hp = 10;
	setTexture("triangle_full_hp.png");
	//以上
}