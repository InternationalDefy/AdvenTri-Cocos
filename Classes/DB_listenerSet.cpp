#include "Ref2ListenerSet.h"

using namespace cocos2d;

void DB_ListenerSet::getLine(const std::string& data)
{
	tempSD = SD_ListenerSet::create();
	tempName = analyseMiddle(data);
	tempSD->setNumberOfDispatcher(std::atoi(analyseMiddle(data).c_str()));
	for (auto i = 0; i < tempSD->getNumberOfDispatcher(); ++i)
	{
		tempSD->pushDispatcherName(analyseMiddle(data));
	}
	tempSD->setNumberOfCallback(std::atoi(analyseMiddle(data).c_str()));
	for (auto i = 0; i < tempSD->getNumberOfCallback(); ++i)
	{
		tempSD->pushCallbackName(analyseMiddle(data));
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_ListenerSet* DB_ListenerSet::getListenerSetSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "ListenerSet String Data Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_ListenerSet);
