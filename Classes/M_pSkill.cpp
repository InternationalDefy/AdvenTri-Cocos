#include "Ref2Pskill.h"

USING_NS_CC;

void M_pSkill::active(){}

void M_pSkill::initCoolDown(SD_pSkill* breed)
{
	_coolDownTime = breed->getCoolDownTime();
	return;
}

M_Player* M_pSkill::getOwner()
{
	return _owner;
}

void M_pSkill::setOwner(M_Player* player)
{
	_owner = player;
	return;
}
