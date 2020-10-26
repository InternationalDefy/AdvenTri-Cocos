#include "Ref2Callback.h"

using namespace cocos2d;

void DB_Callback::getLine(const std::string& data)
{
	tempSD = SD_Callback::create();
	tempName = analyseMiddle(data);
	tempSD->setUprecivingEventName(analyseMiddle(data));
	tempSD->setFixedProximity(std::atoi(analyseMiddle(data).c_str()));
	tempSD->setSwallow(std::atoi(analyseMiddle(data).c_str()));
	tempSD->setCoolDownTime(std::atof(analyseMiddle(data).c_str()));
	tempSD->setLimitedTimes(std::atoi(analyseMiddle(data).c_str()));
	tempSD->setCallbackFuncType(analyseMiddle(data));
	tempSD->setNumberOfParams(std::atoi(analyseMiddle(data).c_str()));
	for (auto i = 0; i < tempSD->getNumberOfParams(); ++i)
	{
		tempSD->pushString(analyseMiddle(data));
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_Callback* DB_Callback::getCallbackSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Callback String Data Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Callback);
