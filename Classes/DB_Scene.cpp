#include "Ref2SceneSystem.h"

USING_NS_CC;

void DB_Scene::getLine(const std::string& data)
{
	tempSD = SD_Scene::create();
	tempName = analyseMiddle(data);
	int NumberOfGameLayer = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfGameLayer(NumberOfGameLayer);
	int NumberOfSplashScene = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfSplashScene(NumberOfSplashScene);
	analyseEndln(data);
	analyseEndln(data);
	for (int i = 0; i < NumberOfGameLayer; ++i)
	{
		SD_Scene::SD_Item_Scene sp;
		int NumberOfScript = std::atoi(analyseMiddle(data).c_str());
		sp.numberOfScripts = NumberOfScript;
		for (int j = 0; j < NumberOfScript; ++j)
		{
			sp.scripts.pushBack(String::create(analyseMiddle(data).c_str()));
		}
		analyseEndln(data);
		sp.itemName = analyseMiddle(data);
		tempSD->pushGameLayerItem(sp);
		analyseEndln(data);
	}
	analyseEndln(data);
	for (int i = 0; i < NumberOfSplashScene; ++i)
	{
		SD_Scene::SD_Item_Scene sp;
		int NumberOfScript = std::atoi(analyseMiddle(data).c_str());
		sp.numberOfScripts = NumberOfScript;
		for (int j = 0; j < NumberOfScript; ++j)
		{
			sp.scripts.pushBack(String::create(analyseMiddle(data).c_str()));
		}
		analyseEndln(data);
		sp.itemName = analyseMiddle(data);
		tempSD->pushSplashSceneItem(sp);
		analyseEndln(data);
	}
	analyseEndln(data);
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

SD_Scene* DB_Scene::getSceneSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Scene StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_Scene);