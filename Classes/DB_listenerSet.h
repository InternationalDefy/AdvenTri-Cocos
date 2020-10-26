#ifndef __DB_LISTENINGSET__
#define __DB_LISTENINGSET__

#include "Ref_DataBase.h"

class SD_ListenerSet;

using namespace cocos2d;

class DB_ListenerSet :public DB
{
private:
	SD_ListenerSet* tempSD;
	std::string tempName;

	Map<std::string, SD_ListenerSet*> _table;
public:
	std::string useString(){ return "Table_ListenerSet.csv"; }
	void getLine(const std::string& data);

	static DB_ListenerSet* create();
	static DB_ListenerSet* getInstance();

	SD_ListenerSet* getListenerSetSD(const std::string& name);
};

#endif