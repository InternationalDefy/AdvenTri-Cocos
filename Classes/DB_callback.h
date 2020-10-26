#ifndef __DB_CALLBACK__
#define __DB_CALLBACK__

#include "Ref_DataBase.h"

class SD_Callback;

using namespace cocos2d;

class DB_Callback :public DB
{
private:
	SD_Callback* tempSD;
	std::string tempName;

	Map<std::string, SD_Callback*> _table;
public:
	std::string useString(){ return "Table_Callback.csv"; }
	void getLine(const std::string& data);

	static DB_Callback* create();
	static DB_Callback* getInstance();

	SD_Callback* getCallbackSD(const std::string& name);
};

#endif