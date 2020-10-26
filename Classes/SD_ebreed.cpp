#include "Ref2Ebreed.h"

using namespace cocos2d;

void SD_Ebreed::init()
{
	_textureName = "";
	_id = 0;
	_amor_type_name = "";
	_unit_type_name = "";
	_animation_pack_name = "";
	_physics_body_name = "";
	_weapon_type_name = "";
	_event_listener_name = "";
	_ui_collection_id = 0;
	_controller_name = "";
}

SD_Ebreed* SD_Ebreed::create()
{
	SD_Ebreed* e_Breed = new (std::nothrow)SD_Ebreed();
	if (e_Breed)
	{
		e_Breed->init();
		e_Breed->autorelease();
		return e_Breed;
	}
	CC_SAFE_DELETE(e_Breed);
	return nullptr;
}

M_Enemy* SD_Ebreed::createFromEbreed()
{
	auto e_temp = M_Enemy::create(_textureName);
	if (_amor_type_name!="")
	{
		DB_Amor::getInstance()->addAmorToEntity(_amor_type_name, e_temp);
	}
	if (_unit_type_name!="")
	{
		DB_Unit::getInstance()->handleUnitType(_unit_type_name, e_temp);
	}
	if (_animation_pack_name!="")
	{
	//	e_temp->addAnimationPack(DB_AnimationPack::getInstance()->getAnimationPack(_animation_pack_name));
	}
	if (_physics_body_name!="")
	{
		e_temp->setPhysicsBody(DB_Physics::getInstance()->getBody(_physics_body_name));
	}
	if (_weapon_type_name!="")
	{
		DB_Weapon::getInstance()->addWeaponToEnemy(_weapon_type_name, e_temp);
	}
	if (_event_listener_name!="")
	{
		Sys_Event::getInstance()->addListenerSetTo(e_temp, _event_listener_name);
	}
	if (_ui_collection_id){}
	if (_controller_name!="")
	{
		e_temp->setController(Sys_Ctrl::getInstance()->getControllerWithName(_controller_name));
	}
	return e_temp;
}