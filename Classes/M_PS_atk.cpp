#include "Ref2pSkill.h"

using namespace cocos2d;

void M_PS_atk::init(SD_pSkill* breed)
{
}

M_PS_atk* M_PS_atk::create(SD_pSkill* breed)
{
	M_PS_atk* a_Breed = new (std::nothrow)M_PS_atk();
	if (a_Breed)
	{
		a_Breed->initCoolDown(breed);
		a_Breed->init(breed);
		a_Breed->autorelease();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}
void M_PS_atk::active()
{
	log("ATK Actived!");
}
