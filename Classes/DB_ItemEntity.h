#ifndef __DB_ITEMENTITY__
#define __DB_ITEMENTITY__

#include "Ref_DataBase.h"

class SD_ItemEntity;

using namespace cocos2d;

class DB_ItemEntity :public DB
{
private:
	SD_ItemEntity* tempSD;
	std::string tempName;

	Map<std::string, SD_ItemEntity*> _table;
public:
	std::string useString(){ return "Table_ItemEntity.csv"; }
	void getLine(const std::string& data);

	static DB_ItemEntity* create();
	static DB_ItemEntity* getInstance();

	SD_ItemEntity* getItemEntitySD(const std::string& name);
};

#endif