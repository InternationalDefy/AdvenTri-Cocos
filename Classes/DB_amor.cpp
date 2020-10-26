#include "Ref2Ebreed.h"

USING_NS_CC;

void DB_Amor::getLine(const std::string &data)
{
	tempBreed = SD_Amor::create();
	tempName = analyseMiddle(data);
	tempBreed->_defence = std::atoi(analyseMiddle(data).c_str());
	tempBreed->_hp = std::atoi(analyseMiddle(data).c_str());
	tempBreed->_type = AdvenTriEnum::changeStringToAmorType(analyseEndln(data)); 
	_amorTable.insert(tempName, tempBreed);
}

CREATE_DB(DB_Amor);

void DB_Amor::addAmorToEntity(const std::string& name, M_Enemy* enemy)
{
	if (_amorTable.at(name))
	{
		_amorTable.at(name)->addToEntity(enemy);
	}
	else
	{
		auto k = "Amor Name:" + name + " UnFound!";
		log(k.c_str());
	}
	return;
}