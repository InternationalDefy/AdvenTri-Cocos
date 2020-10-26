#ifndef __SD_WBREED__
#define __SD_WBREED__

#include "cocos2d.h"
#include "Ref_Enum.h"

USING_NS_CC;

class M_Enemy;

class SD_Wbreed : public Ref
{
public:
	std::string _physics_body_name;
	std::string _textureName;
	std::string _broken_animation_name;
	int _damage;
	AdvenTriEnum::DamageType _damageType;
	void init();
public:
	static SD_Wbreed* create();

	//M_Enemy* createFromEbreed(){};
	void addToEntity(M_Enemy* enemy);
};
#endif