#include "Ref2Enemy.h"

USING_NS_CC;

//void M_Enemy::update(float dt){}
void M_Enemy::destroy(){}

M_Enemy* M_Enemy::create(const std::string& filename)
{
	M_Enemy *enemy = new (std::nothrow) M_Enemy();
	if (enemy && enemy->initWithFile(filename))
	{
		//entity->setActionRunning(false);
		enemy->initData();
		enemy->initEntity();
		enemy->autorelease();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return nullptr;
}
void M_Enemy::initData()
{
	setLocalZOrder(0);
	_state = ES_Standred::create();
	_state->setOwner(this);
	_animateRunning = false;
	_amor = NULL;
	_weapon = NULL;
	//_animationPack = NULL;
	_hurting = false;
	_debuffNode = Sprite::create("2.png");
	_debuffNode->setOpacity(196);
	this->addChild(_debuffNode);
	_debuffNode->setLocalZOrder(2);
	_onDebuffLimit = 0;
	for (auto i = 0; i <= 6; ++i)
	{
		AdvenTriEnum::Debuff k = static_cast<AdvenTriEnum::Debuff> (i);
		_onDebuff.insert(std::make_pair(k, false));
		_debuffTime.insert(std::make_pair(k, 0));
		_debuffLimit.insert(std::make_pair(k, DEBUFF_LIMIT));
		_debuffCount.insert(std::make_pair(k, 0));
	}
}

void M_Enemy::addAmor(M_Amor* amor)
{
	_amor = amor;
	addChild(_amor);
	_hp = amor->_hp;
	_amor->setLocalZOrder(1);
}
void M_Enemy::addWeapon(M_weapon* weapon)
{
	_weapon = weapon;
	addChild(_weapon);
	_weapon->setLocalZOrder(1);
}
void M_Enemy::addSkill(const std::string& position,SD_Eskill* SD)
{
	//handleCoolDown maybe
	auto skill = M_Eskill::create(SD);
	_skillReady.insert(std::make_pair(position, false));
	_skillCooldown.insert(std::make_pair(position, 0));
	_skillLimit.insert(std::make_pair(position,SD->_cooldown));
	_skills.insert(position, skill);
	skill->setOwner(this);
}
/*
void M_Enemy::addAnimationPack(M_AnimationPack* animationPack)
{
	_animationPack = animationPack;
}
*/
void M_Enemy::handleAction(AdvenTriEnum::EnemyAction action)
{
	_state->handleAction(action);
	return;
}
//state操作
void M_Enemy::setState(M_EnemyState* state)
{
	if (_state)
	{
		state->setOwner(this);
		state->enterFrom(_state);
		_state = state;
	}
	else
	{
		_state = state;
		state->setOwner(this);
	}
}
Vec2 M_Enemy::getDashVec2()
{
	return _controller->getDashVec2();
}
//更新操作
void M_Enemy::update(float dt)
{
	updateLogic(dt);
	for (auto i : _children)
	{
		i->update(dt);
	}
	//log ("UpdateState!");
}
void M_Enemy::updateLogic(float dt)
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
void M_Enemy::updateSkillCooldown(const std::string& name, float dt)
{
	_skillCooldown.at(name) += dt;
	if (_skillCooldown.at(name) >= _skillLimit.at(name))
	{
		_skillReady.at(name) = true;
		return;
	}
	return;
}