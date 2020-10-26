#ifndef __DB_UIITEM__
#define __DB_UIITEM__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_UIItem;

class DB_UIItem : public DB
{
private:
	SD_UIItem* tempSD;
	std::string tempName;

	Map<std::string, SD_UIItem*> _table;
public:
	std::string useString(){ return "Table_UIItem.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 2; }

	static DB_UIItem* create();
	static DB_UIItem* getInstance();

	SD_UIItem* getUIItemSD(const std::string& name);
};

#endif