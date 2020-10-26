#ifndef __DB_DISPATCHER__
#define __DB_DISPATCHER__

#include "Ref_DataBase.h"

class SD_Dispatcher;

using namespace cocos2d;

class DB_Dispatcher :public DB
{
private:
	SD_Dispatcher* tempSD;
	std::string tempName;

	Map<std::string, SD_Dispatcher*> _table;
public:
	std::string useString(){ return "Table_Dispatcher.csv"; }
	void getLine(const std::string& data);

	static DB_Dispatcher* create();
	static DB_Dispatcher* getInstance();

	SD_Dispatcher* getDispatcherSD(const std::string& name);
};

#endif