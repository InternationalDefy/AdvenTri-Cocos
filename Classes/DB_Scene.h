#ifndef __DB_SCENE__
#define __DB_SCENE__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_Scene;

class DB_Scene : public DB
{
private:
	SD_Scene* tempSD;
	std::string tempName;

	Map<std::string, SD_Scene*> _table;
public:
	std::string useString(){ return "Table_Scene.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 8; }

	static DB_Scene* create();
	static DB_Scene* getInstance();

	SD_Scene* getSceneSD(const std::string& name);
};

#endif