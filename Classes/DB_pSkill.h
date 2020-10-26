#ifndef __DB_PLAYER_SKILL__
#define __DB_PLAYER_SKILL__

#include "Ref_DataBase.h"

class SD_pSkill;
class M_Player;

using namespace cocos2d;

class DB_pSkill:public DB
{
private:
	std::string tempName;
	SD_pSkill* tempSD;

	Map<std::string, SD_pSkill*> _table;
public:
	std::string useString(){ return "Table_PlayerSkill.csv"; }
	void getLine(const std::string& data);

	static DB_pSkill* create();
	static DB_pSkill* getInstance();

	void addSkillToPlayer(const std::string& name,M_Player* player);

};

#endif