#include "Ref2Ebreed.h"
USING_NS_CC;

void DB_Unit::getLine(const std::string &data)
{
	tempBreed = SD_Ubreed::create();
	tempName = analyseMiddle(data);
	int x = std::atoi(analyseMiddle(data).c_str());
	for (int j = 1; j <= x; ++j)
	{
		auto s_temp = SD_Eskill::create();
		s_temp->_cooldown = std::atof(analyseMiddle(data).c_str());
		s_temp->_positionName = analyseMiddle(data);
		s_temp->_type = analyseMiddle(data);
		int y = std::atoi(analyseMiddle(data).c_str());
		for (int u = 1; u <= y; ++u)
		{
			s_temp->_params.push_back(analyseMiddle(data));
		}
		tempBreed->_skill_data.pushBack(s_temp);
	}
	analyseEndln(data);
	_breedTable.insert(tempName,tempBreed);
}

CREATE_DB(DB_Unit);

void DB_Unit::handleUnitType(const std::string& name, M_Enemy* enemy)
{
	if (_breedTable.at(name))
	{
		_breedTable.at(name)->addToEntity(enemy);
	}
	else
	{
		auto k = "Unit Type Name " + name + " UNFOUND!";
		log(k.c_str());
	}
}