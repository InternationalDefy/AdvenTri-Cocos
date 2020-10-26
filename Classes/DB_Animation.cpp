#include "Ref2Animation.h"

using namespace cocos2d;

void DB_Animation::getLine(const std::string& data)
{
	tempSD = SD_Animation::create();
	tempName = analyseMiddle(data);

	tempSD->setAnimationTypeName(analyseMiddle(data));
	tempSD->setNumberOfParams(std::atoi(analyseMiddle(data).c_str()));
	if (tempSD->getNumberOfParams())
	{
		for (auto i = 0; i < tempSD->getNumberOfParams(); ++i)
		{
			tempSD->pushParam(analyseMiddle(data));
		}
	}	

	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_Animation* DB_Animation::getAnimationSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Animation StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Animation);