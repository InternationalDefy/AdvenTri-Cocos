#include "Ref2Ebreed.h"

using namespace cocos2d;

void SD_Wbreed::init()
{
	_textureName = "";
	_physics_body_name = "";
	_broken_animation_name = "";
	_damage = 0;
	_damageType = AdvenTriEnum::DamageType::D_TYPE_COMMON;
}

SD_Wbreed* SD_Wbreed::create()
{
	SD_Wbreed* e_Breed = new (std::nothrow)SD_Wbreed();
	if (e_Breed)
	{
		e_Breed->init();
		return e_Breed;
	}
	CC_SAFE_DELETE(e_Breed);
	return nullptr;
}

void SD_Wbreed::addToEntity(M_Enemy* enemy)
{
	auto w_temp = M_weapon::create(this);
	w_temp->addToEnemy(enemy);
}