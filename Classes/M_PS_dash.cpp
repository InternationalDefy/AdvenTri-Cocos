#include "Ref2pSkill.h"

using namespace cocos2d;

void M_PS_dash::init(SD_pSkill* breed)
{
	dashMulti =std::atof(breed->getStrings()->at(0)->getCString());
}

M_PS_dash* M_PS_dash::create(SD_pSkill* breed)
{
	M_PS_dash* a_Breed = new (std::nothrow)M_PS_dash();
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
void M_PS_dash::active()
{
	Vec2 dashVec = getOwner()->getpCtrl()->getDashVec2();
	dashVec.x *= dashMulti;
	dashVec.y *= dashMulti;
	getOwner()->getPhysicsBody()->applyImpulse(dashVec);
	return;
}
