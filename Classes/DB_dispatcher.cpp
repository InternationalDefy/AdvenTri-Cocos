#include "Ref2Dispatcher.h"

using namespace cocos2d;

void DB_Dispatcher::getLine(const std::string& data)
{
	tempSD = SD_Dispatcher::create();
	tempName = analyseMiddle(data);
	tempSD->setUpsendingEventName(analyseMiddle(data));
	tempSD->setCooldownTime(std::atof(analyseMiddle(data).c_str()));
	tempSD->setLimitTimes(std::atoi(analyseMiddle(data).c_str()));
	tempSD->setListeningFuncType(analyseMiddle(data));
	tempSD->setNumberOfParamas(std::atoi(analyseMiddle(data).c_str()));
	for (auto i = 0; i < tempSD->getNumberOfParamas(); ++i)
	{
		tempSD->pushString(analyseMiddle(data));
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_Dispatcher* DB_Dispatcher::getDispatcherSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Dispatcher String Data Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Dispatcher);
