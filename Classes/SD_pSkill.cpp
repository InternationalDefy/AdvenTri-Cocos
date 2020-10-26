#include "Ref2pSkill.h"

using namespace cocos2d;

bool SD_pSkill::init()
{
	_PositionName = "";
	_TypeName = "";
	_CoolDownTime = 0;
	return true;
}

SD_pSkill* SD_pSkill::create()
{
	SD_pSkill* pRet = new(std::nothrow) SD_pSkill();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

M_pSkill* SD_pSkill::handleSkillType(const std::string& typeName)
{
	if (_TypeName == "atk")
	{
		return M_PS_atk::create(this);
	}
	if (_TypeName == "spk")
	{
		return M_PS_spk::create(this);
	}
	if (_TypeName == "dash")
	{
		return M_PS_dash::create(this);
	}
	log("UN DEFINED TYPE");
	return NULL;
}

void SD_pSkill::addSkillToPlayer(M_Player* player)
{
	player->addSkill(getPositionName(), handleSkillType(_TypeName));
}