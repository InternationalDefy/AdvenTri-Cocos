#include "Ref2Pskill.h"

using namespace cocos2d;

void DB_pSkill::getLine(const std::string& data)
{
	tempSD = SD_pSkill::create();
	tempName = analyseMiddle(data);
	tempSD->setPositionName(analyseMiddle(data));
	tempSD->setCoolDownTime(std::atof(analyseMiddle(data).c_str()));
	tempSD->setTypeName(analyseMiddle(data));
	int k = std::atoi(analyseMiddle(data).c_str());
	if (k != 0)
	for (int i = 0; i < k; ++i)
	{
		tempSD->getStrings()->pushBack(String::create(analyseMiddle(data)));
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

void DB_pSkill::addSkillToPlayer(const std::string& name,M_Player* player)
{
	if (_table.at(name))
	{
		_table.at(name)->addSkillToPlayer(player);
		return;
	}
	else
	{
		auto k = "Player Ctrl_Base Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_pSkill);