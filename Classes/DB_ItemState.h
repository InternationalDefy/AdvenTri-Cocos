#ifndef __DB_ITEMSTATE__
#define __DB_ITEMSTATE__

#include "Ref_DataBase.h"

class SD_ItemState;

using namespace cocos2d;

class DB_ItemState :public DB
{
private:
	SD_ItemState* tempSD;
	std::string tempName;

	Map<std::string, SD_ItemState*> _table;
public:
	std::string useString(){ return "Table_ItemState.csv"; }
	void getLine(const std::string& data);

	static DB_ItemState* create();
	static DB_ItemState* getInstance();

	SD_ItemState* getItemStateSD(const std::string& name);
};

#endif