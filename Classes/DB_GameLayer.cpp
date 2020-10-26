#include "Ref2SceneSystem.h"

USING_NS_CC;

void DB_GameLayer::getLine(const std::string& data)
{
	tempSD = SD_GameLayer::create();
	tempName = analyseMiddle(data);
	analyseEndln(data);
	
	tempSD->setListenerSetName(analyseMiddle(data).c_str());
	analyseEndln(data);

	tempSD->setGameLayerTag(analyseMiddle(data));
	analyseEndln(data);

	analyseEndln(data);
	int NumberOfBackGround = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfBackGround(NumberOfBackGround);
	analyseEndln(data);
	
	for (auto i = 0; i < NumberOfBackGround; ++i)
	{
		SD_GameLayer::SD_Item_BackGround bg;
		int NumberOfScript = std::atoi(analyseMiddle(data).c_str());
		bg.numberOfScripts = NumberOfScript;
		for (auto j = 0; j < NumberOfScript; ++j)
		{
			bg.scripts.pushBack(String::create(analyseMiddle(data).c_str()));
		}
		analyseEndln(data);
			
		bg.image = analyseMiddle(data).c_str();
		float x = std::atof(analyseMiddle(data).c_str());
		float y = std::atof(analyseMiddle(data).c_str());
		float z = std::atof(analyseMiddle(data).c_str());
		bg.position3D = Vec3(x, y, z);
		bg.localZOrder = std::atoi(analyseMiddle(data).c_str());
		analyseEndln(data);

		bg.enableAction = std::atoi(analyseMiddle(data).c_str());
		if (bg.enableAction)
		{
			bg.actionType = analyseMiddle(data).c_str();
			auto NumberOfParam = std::atoi(analyseMiddle(data).c_str());
			for (auto k = 0; k < NumberOfParam; ++k)
			{
				bg.actionParams.pushBack(String::create(analyseMiddle(data).c_str()));
			}
		}
		analyseEndln(data);

		bg.enableListener = std::atoi(analyseMiddle(data).c_str());
		if (bg.enableListener)
		{
			bg.listenerSetName = analyseMiddle(data).c_str();
		}
		analyseEndln(data);
		
		tempSD->pushBackgroundItem(bg);
	}
	
	analyseEndln(data);
	int NumberOfNpc = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfNpc(NumberOfNpc);
	analyseEndln(data);
	
	if (NumberOfNpc)
	{
		for (auto i = 0; i < NumberOfNpc; ++i)
		{
			SD_GameLayer::SD_Item_Entity et;
			int NumberOfScript = std::atoi(analyseMiddle(data).c_str());
			et.numberOfScripts = NumberOfScript;
			for (auto j = 0; j < NumberOfScript; ++j)
			{
				et.scripts.pushBack(String::create(analyseMiddle(data).c_str()));
			}
			analyseEndln(data);

			et.itemTag = analyseMiddle(data).c_str();
			et.itemName = analyseMiddle(data).c_str();
			float x = std::atof(analyseMiddle(data).c_str());
			float y = std::atof(analyseMiddle(data).c_str());
			float z = std::atof(analyseMiddle(data).c_str());
			et.position3D = Vec3(x, y, z);
			et.localZOrder = std::atoi(analyseMiddle(data).c_str());
			analyseEndln(data);

			tempSD->pushNpcItem(et);
		}
	}

	analyseEndln(data);
	int NumberOfEnemy = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfEnemy(NumberOfEnemy);
	analyseEndln(data);

	if (NumberOfEnemy)
	{
		for (auto i = 0; i < NumberOfEnemy; ++i)
		{
			SD_GameLayer::SD_Item_Entity et;
			int NumberOfScript = std::atoi(analyseMiddle(data).c_str());
			et.numberOfScripts = NumberOfScript;
			for (auto j = 0; j < NumberOfScript; ++j)
			{
				et.scripts.pushBack(String::create(analyseMiddle(data).c_str()));
			}
			analyseEndln(data);

			et.itemTag = analyseMiddle(data).c_str();
			et.itemName = analyseMiddle(data).c_str();
			float x = std::atof(analyseMiddle(data).c_str());
			float y = std::atof(analyseMiddle(data).c_str());
			float z = std::atof(analyseMiddle(data).c_str());
			et.position3D = Vec3(x, y, z);
			et.localZOrder = std::atoi(analyseMiddle(data).c_str());
			analyseEndln(data);

			tempSD->pushEnemyItem(et);
		}
	}

	analyseEndln(data);
	int NumberOfBorder = std::atoi(analyseMiddle(data).c_str());
	tempSD->setNumberOfPhysicsBorder(NumberOfBorder);
	analyseEndln(data);

	if (NumberOfBorder)
	{
		for (auto i = 0; i < NumberOfBorder; ++i)
		{
			SD_GameLayer::SD_Item_Border bd;
			float x = std::atof(analyseMiddle(data).c_str());
			float y = std::atof(analyseMiddle(data).c_str());
			bd.position = Vec2(x, y);
			bd.width = std::atof(analyseMiddle(data).c_str());
			bd.height = std::atof(analyseMiddle(data).c_str());
			analyseEndln(data);
			tempSD->pushBorderItem(bd);
		}
	}

	analyseEndln(data);
	_table.insert(tempName, tempSD);
	return;
}

SD_GameLayer* DB_GameLayer::getGameLayerSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "GameLayer StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_GameLayer);