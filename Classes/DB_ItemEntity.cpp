#include "Ref2ItemEntity.h"

using namespace cocos2d;

void DB_ItemEntity::getLine(const std::string& data)
{
	tempSD = SD_ItemEntity::create();
	tempName = analyseMiddle(data);
	tempSD->setItemName(tempName);
	tempSD->setTextureName(analyseMiddle(data));
	tempSD->setItemState(analyseMiddle(data));
	tempSD->setPhysicsBodyName(analyseMiddle(data));
	tempSD->setDropDelay(std::atof(analyseMiddle(data).c_str()));
	tempSD->setTimeExist(std::atof(analyseMiddle(data).c_str()));
	tempSD->setDropController(analyseMiddle(data));
	tempSD->setDropAnimateName(analyseMiddle(data));
	tempSD->setFlyingController(analyseMiddle(data));
	tempSD->setFlyingEndFuncName(analyseMiddle(data));
	tempSD->setNumberOfFlyEndFuncParams(std::atoi(analyseMiddle(data).c_str()));
	if (tempSD->getNumberOfFlyEndFuncParams())
	{
		for (auto i = 0; i < tempSD->getNumberOfFlyEndFuncParams(); ++i)
		{
			tempSD->pushFlyEndFuncParam(analyseMiddle(data));
		}
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_ItemEntity* DB_ItemEntity::getItemEntitySD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "ItemEntity StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_ItemEntity);
