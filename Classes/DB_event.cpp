#include "Ref2Event.h"

using namespace cocos2d;

void DB_Event::getLine(const std::string& data)
{
	tempSD = SD_Event::create();
	tempName = analyseMiddle(data);
	tempSD->setParamType(analyseMiddle(data));
	tempSD->setParam(analyseEndln(data));
	_table.insert(tempName, tempSD);
}

SD_Event* DB_Event::getEventSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Event String Data Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Event);
