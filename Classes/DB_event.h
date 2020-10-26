#ifndef __DB_EVENTS__
#define __DB_EVENTS__

#include "Ref_DataBase.h"

class SD_Event;

using namespace cocos2d;

class DB_Event :public DB
{
private:
	SD_Event* tempSD;
	std::string tempName;

	Map<std::string, SD_Event*> _table;
public:
	std::string useString(){ return "Table_Event.csv"; }
	void getLine(const std::string& data);

	static DB_Event* create();
	static DB_Event* getInstance();

	SD_Event* getEventSD(const std::string& name);
};

#endif