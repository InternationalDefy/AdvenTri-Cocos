#ifndef __SD_PLAYER_SKILL__
#define __SD_PLAYER_SKILL__

#include "Ref_DataBase.h"

class M_pSkill;
class M_Player;

using namespace cocos2d;

class SD_pSkill :public SD_Item
{
private:
	ASSIGN_STRING(PositionName);
	//ASSIGN_STRING(Name);
	ASSIGN_DATA(float, CoolDownTime);
	ASSIGN_STRING(TypeName);
	//ASSIGN_ITEMS();
private:
	bool init();
private:
	M_pSkill* handleSkillType(const std::string& typeName);
public:
	static SD_pSkill* create();
	void addSkillToPlayer(M_Player* player);
};


#endif