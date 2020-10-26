#include "Ref2ItemState.h"

using namespace cocos2d;

void DB_ItemState::getLine(const std::string& data)
{
	tempSD = SD_ItemState::create();
	tempName = analyseMiddle(data);
	tempSD->setItemName(tempName);
	tempSD->setUISetName(analyseMiddle(data));
	tempSD->setItemEntity(analyseMiddle(data));
	tempSD->setUsingTime(std::atof(analyseMiddle(data).c_str()));
	tempSD->setUsingAnimateName(analyseMiddle(data));
	tempSD->setPickUpAnimate(analyseMiddle(data));
	tempSD->setDropFuncName(analyseMiddle(data));
	tempSD->setNumberOfDropFuncParams(std::atoi(analyseMiddle(data).c_str()));
	if (tempSD->getNumberOfDropFuncParams())
	{
		for (auto i = 0; i < tempSD->getNumberOfDropFuncParams(); ++i)
		{
			tempSD->pushDropFuncParam(analyseMiddle(data));
		}
	}
	tempSD->setNumberOfUseFunc(std::atoi(analyseMiddle(data).c_str()));
	if (tempSD->getNumberOfUseFunc())
	{
		for (auto i = 0; i < tempSD->getNumberOfUseFunc(); ++i)
		{
			auto s = SD_Item::create();
			s->pushIn(String::create(analyseMiddle(data)));
			int k = std::atoi(analyseMiddle(data).c_str());
			if (k)
			{
				for (auto j = 0; j < k; ++j)
				{
					s->pushIn(String::create(analyseMiddle(data)));
				}
			}
			tempSD->getLines()->pushBack(s);
		}
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_ItemState* DB_ItemState::getItemStateSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "ItemState StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_ItemState);
