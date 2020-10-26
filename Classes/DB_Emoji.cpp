#include "Ref2LaEmoji.h"

using namespace cocos2d;

void DB_Emoji::getLine(const std::string& data)
{
	tempSD = SD_Emoji::create();
	tempName = analyseMiddle(data);
	tempSD->setFileName(analyseMiddle(data));
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_Emoji* DB_Emoji::getEmojiSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Emoji StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Emoji);
