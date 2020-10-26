#include "Ref2Ebreed.h"

using namespace cocos2d;

void M_weapon::initWithData(SD_Wbreed* w_breed)
{
	if (w_breed->_textureName!="") initWithFile(w_breed->_textureName);
	//if (w_breed->_physics_body_name!="") setPhysicsBody(DB_Physics::getInstance()->getBody(w_breed->_physics_body_name));
	if (w_breed->_broken_animation_name != "")
		_broken_animation = M_ActionHandler::getInstance()->getAction(this, w_breed->_broken_animation_name);
	this->iDamageType = w_breed->_damageType;
	this->iDamagePoint = w_breed->_damage;
}

M_weapon* M_weapon::create(SD_Wbreed* w_breed)
{
	M_weapon* weapon = new (std::nothrow)M_weapon();
	if (weapon)
	{
		weapon->initWithData(w_breed);
		weapon->autorelease();
		return weapon;
	}
	CC_SAFE_DELETE(weapon);
	return nullptr;
}

void M_weapon::addToEnemy(M_Enemy* enemy)
{
	_owner = enemy;
	
	//以下一句测试使用，要改！
	setPosition(enemy->getPosition());

	enemy->addWeapon(this);
}