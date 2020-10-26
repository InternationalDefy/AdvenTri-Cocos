#include "Ref2Dialogue.h"

using namespace cocos2d;

void DB_Dialogue::getLine(const std::string& data)
{
	tempSD = SD_Dialogue::create();
	tempName = analyseMiddle(data);
	auto k = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfPages(k);
	auto x = std::atof(analyseMiddle(data).c_str());
	auto y = std::atof(analyseMiddle(data).c_str());
	tempSD->setOnSetPosition(Vec2(x, y));
	tempSD->setOpacity(std::atoi(analyseMiddle(data).c_str()));
	analyseEndln(data);
	tempSD->setEnterActionType(analyseMiddle(data).c_str());
	auto etn = std::atoi(analyseMiddle(data).c_str());
	for (auto i = 0; i < etn; ++i)
	{
		tempSD->pushEnterActionParam(analyseMiddle(data).c_str());
	}
	analyseEndln(data);
	tempSD->setExitActionType(analyseMiddle(data).c_str());
	auto exn = std::atoi(analyseMiddle(data).c_str());
	for (auto i = 0; i < exn; ++i)
	{
		tempSD->pushExitActionParam(analyseMiddle(data).c_str());
	}
	analyseEndln(data);
	for (auto j = 0; j < k; ++j)
	{
		auto sd = SD_PageDialogue::create();
		sd->setBackGroundName(analyseMiddle(data).c_str());
		sd->setCharIconName(analyseMiddle(data).c_str());
		auto cx = std::atof(analyseMiddle(data).c_str());
		auto cy = std::atof(analyseMiddle(data).c_str());
		sd->setCharIconOffset(Vec2(cx, cy));
		analyseEndln(data);
		sd->setLaEmojiName(analyseMiddle(data).c_str());
		auto px = std::atof(analyseMiddle(data).c_str());
		auto py = std::atof(analyseMiddle(data).c_str());
		sd->setLaEmojiPosition(Vec2(px, py));
		auto m = std::atoi(analyseMiddle(data).c_str());
		sd->setNumberOfItems(m);
		analyseEndln(data);
		sd->setEnterActionType(analyseMiddle(data).c_str());
		auto ek = std::atoi(analyseMiddle(data).c_str());
		for (auto i = 0; i < ek; ++i)
		{
			sd->pushEnterActionParam(analyseMiddle(data).c_str());
		}
		analyseEndln(data);
		sd->setExitActionType(analyseMiddle(data).c_str());
		auto ee = std::atoi(analyseMiddle(data).c_str());
		for (auto i = 0; i < ee; ++i)
		{
			sd->pushExitActionParam(analyseMiddle(data).c_str());
		}
		analyseEndln(data);
		sd->setLaCtrlName1(analyseMiddle(data).c_str());
		auto x1 = std::atof(analyseMiddle(data).c_str());
		auto y1 = std::atof(analyseMiddle(data).c_str());
		sd->setLaCtrlOffSet1(Vec2(x1, y1));
		sd->setLaCtrlOpacity1(std::atoi(analyseMiddle(data).c_str()));
		analyseEndln(data);
		sd->setLaCtrlName2(analyseMiddle(data).c_str());
		auto x2 = std::atof(analyseMiddle(data).c_str());
		auto y2 = std::atof(analyseMiddle(data).c_str());
		sd->setLaCtrlOffSet2(Vec2(x2, y2));
		sd->setLaCtrlOpacity2(std::atoi(analyseMiddle(data).c_str()));
		analyseEndln(data);
		for (auto i = 0; i < m; ++i)
		{
			sd->pushDiaCtrlItemName(analyseMiddle(data).c_str());
			auto xd = std::atof(analyseMiddle(data).c_str());
			auto yd = std::atof(analyseMiddle(data).c_str());
			sd->pushDiaCtrlItemOffSet(Vec2(xd, yd));
			sd->pushDiaCtrlItemOpacity(std::atoi(analyseMiddle(data).c_str()));
			analyseEndln(data);
		}
		tempSD->pushPageSD(sd);
	}
	_table.insert(tempName, tempSD);
	return;
}

SD_Dialogue* DB_Dialogue::getDialogueSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Dialogue StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}
CREATE_DB(DB_Dialogue);