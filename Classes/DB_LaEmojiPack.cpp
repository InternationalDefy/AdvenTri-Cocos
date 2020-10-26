#include "Ref2LaEmoji.h"

using namespace cocos2d;

void DB_LaEmojiPack::getLine(const std::string& data)
{
	tempSD = SD_LaEmojiPack::create();
	tempName = analyseMiddle(data);
	auto k = std::atoi(analyseMiddle(data).c_str());
	for (auto i = 0; i < k; ++i)
	{
		tempSD->pushKey(analyseMiddle(data));
		tempSD->pushLaEmoji(analyseMiddle(data));
	}
	analyseEndln(data);
	_table.insert(tempName, tempSD);
	return;
}

SD_LaEmojiPack* DB_LaEmojiPack::getLaEmojiPackSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "LaEmojiPack StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_LaEmojiPack);
