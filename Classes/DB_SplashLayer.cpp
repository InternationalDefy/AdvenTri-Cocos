#include "Ref2SceneSystem.h"

USING_NS_CC;

void DB_SplashLayer::getLine(const std::string& data)
{
	tempSD = SD_SplashLayer::create();
	tempName = analyseMiddle(data);
	int NumberOfSprite = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfSprite(NumberOfSprite);
	analyseEndln(data);

	for (int i = 0; i < NumberOfSprite; ++i)
	{
		SD_SplashLayer::SD_Item_SplashScene sp;
		sp.image = analyseMiddle(data);
		sp.position = Vec3(std::atof(analyseMiddle(data).c_str()), 
			std::atof(analyseMiddle(data).c_str()), std::atof(analyseMiddle(data).c_str()));
		sp.localZorder = std::atoi(analyseMiddle(data).c_str());
		analyseEndln(data);
		sp.enableAction = std::atoi(analyseMiddle(data).c_str());
		if (sp.enableAction)
		{
			sp.actionType = analyseMiddle(data).c_str();
			sp.numberActionParam = std::atoi(analyseMiddle(data).c_str());
			for (auto j = 0; j < sp.numberActionParam; ++j)
			{
				sp.actionParam.push_back(analyseMiddle(data).c_str());
			}
		}
		analyseEndln(data);
		sp.enableListenerSet = std::atoi(analyseMiddle(data).c_str());
		if (sp.enableListenerSet)
		{
			sp.listenerSet = analyseMiddle(data).c_str();
		}
		analyseEndln(data);
		tempSD->pushItem(sp);
	}

	/*
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
	*/
	_table.insert(tempName, tempSD);
	return;
}

SD_SplashLayer* DB_SplashLayer::getSplashSceneSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "SplashScene StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_SplashLayer);
