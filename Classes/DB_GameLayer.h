#ifndef __DB_GAMELAYER__
#define __DB_GAMELAYER__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_GameLayer;

class DB_GameLayer : public DB
{
private:
	SD_GameLayer* tempSD;
	std::string tempName;

	Map<std::string, SD_GameLayer*> _table;
public:
	std::string useString(){ return "Table_GameLayer.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 19; }

	static DB_GameLayer* create();
	static DB_GameLayer* getInstance();

	Map<std::string, SD_GameLayer*>* getTable(){ return &_table; }
	SD_GameLayer* getGameLayerSD(const std::string& name);
};

#endif