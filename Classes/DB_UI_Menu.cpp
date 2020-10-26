#include "Ref2UIMenu.h"

USING_NS_CC;

void DB_UIMenu::getLine(const std::string& data)
{
	tempSD = SD_UIMenu::create();
	tempName = analyseMiddle(data);
	tempSD->setCallActived(std::atoi(analyseMiddle(data).c_str()));
	tempSD->setZOrder(std::atoi(analyseMiddle(data).c_str()));
	auto n = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfItems(n);
	analyseEndln(data);
	tempSD->setEnterAnimationType(analyseMiddle(data).c_str());
	auto m = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfEnterAnimationParams(m);
	for (auto i = 0; i < m; ++i)
	{
		tempSD->pushEnterAnimationParam(analyseMiddle(data).c_str());
	}
	analyseEndln(data);

	tempSD->setQuitAnimationType(analyseMiddle(data).c_str());
	auto p = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfQuitAnimationParams(p);
	for (auto i = 0; i < p; ++i)
	{
		tempSD->pushQuitAnimationParam(analyseMiddle(data).c_str());
	}
	analyseEndln(data);

	for (auto i = 0; i < n; ++i)
	{
		auto sd = DB_UIItem::getInstance()->getUIItemSD(analyseMiddle(data).c_str());
		tempSD->pushUIItemStringData(sd);
		tempSD->pushActiveEnterAnimation(std::atoi(analyseMiddle(data).c_str()));
		auto x = std::atof(analyseMiddle(data).c_str());
		auto y = std::atof(analyseMiddle(data).c_str());
		Vec2 vec = Vec2(x, y);
		tempSD->pushOffSetPosition(vec);
		tempSD->pushOffSetOpecity(std::atoi(analyseMiddle(data).c_str()));
		analyseEndln(data);
	}
	_table.insert(tempName, tempSD);
	return;
}

SD_UIMenu* DB_UIMenu::getUIMenuSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "UIMenu StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_UIMenu);