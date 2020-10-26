#include "Ref2Npc.h"

USING_NS_CC;

void DB_Npc::getLine(const std::string& data)
{
	tempSD = SD_Npc::create();
	tempName = analyseMiddle(data);
	tempSD->setTextureName(analyseMiddle(data));
	analyseEndln(data);
	tempSD->setLanguagePackName(analyseMiddle(data));
	tempSD->setAnimationPackName(analyseMiddle(data));
	tempSD->setPhysicsBodyName(analyseMiddle(data));
	tempSD->setListenerSetName(analyseMiddle(data));
	tempSD->setUISetName(analyseMiddle(data));
	tempSD->setControllerName(analyseMiddle(data));
	analyseEndln(data);
	int k = std::atoi(analyseMiddle(data).c_str());
	for (auto i = 0; i < k; ++i)
	{
		auto str = analyseMiddle(data);
		tempSD->setVulnerable(AdvenTriEnum::changeStringToDamageType(str), TRUE);
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
	return;
}

SD_Npc* DB_Npc::getNpcBreed(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Npc Breed StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Npc);