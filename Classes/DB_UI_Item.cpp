#include "Ref2UIItem.h"

USING_NS_CC;

void DB_UIItem::getLine(const std::string& data)
{
	tempSD = SD_UIItem::create();
	tempName = analyseMiddle(data);
	tempSD->setListenerSetName(analyseMiddle(data));
	tempSD->setType(analyseMiddle(data));
	auto k = std::atoi(analyseMiddle(data).c_str());
	analyseEndln(data);
	tempSD->setNumberOfSprites(k);
	for (auto i = 0; i < k; ++i)
	{
		tempSD->pushTextureName(analyseMiddle(data));
		tempSD->pushAnimationPackName(analyseMiddle(data));
		auto x = std::atof(analyseMiddle(data).c_str());
		auto y = std::atof(analyseMiddle(data).c_str());
		tempSD->pushOffSetVec2(Vec2(x, y));
		analyseEndln(data);
	}
	_table.insert(tempName, tempSD);
	return;
}

SD_UIItem* DB_UIItem::getUIItemSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "UIItem StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_UIItem);