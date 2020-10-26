#ifndef __DB_SPLASHSCENE__
#define __DB_SPLASHSCENE__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_SplashLayer;

class DB_SplashLayer : public DB
{
private:
	SD_SplashLayer* tempSD;
	std::string tempName;

	Map<std::string, SD_SplashLayer*> _table;
public:
	std::string useString(){ return "Table_SplashScene.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 4; }

	static DB_SplashLayer* create();
	static DB_SplashLayer* getInstance();

	SD_SplashLayer* getSplashSceneSD(const std::string& name);
};

#endif