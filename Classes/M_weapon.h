#ifndef __M_WEAPON__
#define __M_WEAPON__

#include "cocos2d.h"
#include "Ref_Enum.h"

USING_NS_CC;

class M_Enemy;
class SD_Wbreed;

class M_weapon : public Sprite
{
private:
	void initWithData(SD_Wbreed* w_breed);
	
	void handleTypeID(int id);

	//virtual void update(float dt);

	M_Enemy* _owner;

	FiniteTimeAction* _broken_animation;
public:
	AdvenTriEnum::DamageType iDamageType;
	int iDamagePoint;

	static M_weapon* create(SD_Wbreed* w_breed);

	void addToEnemy(M_Enemy* enemy);
};
#endif