#include "Ref2LaEmoji.h"

using namespace cocos2d;

void DB_Dialog::getLine(const std::string& data)
{
	tempSD = SD_Dialog::create();
	tempName = analyseMiddle(data);
	tempSD->setFileName(analyseMiddle(data));
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_Dialog* DB_Dialog::getDialogSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Dialog StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Dialog);
