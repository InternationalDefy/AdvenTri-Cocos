#ifndef __DB_UIMENU__
#define __DB_UIMENU__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_UIMenu;

class DB_UIMenu : public DB
{
private:
	SD_UIMenu* tempSD;
	std::string tempName;

	Map<std::string, SD_UIMenu*> _table;
public:
	std::string useString(){ return "Table_UIMenu.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 4; }

	static DB_UIMenu* create();
	static DB_UIMenu* getInstance();

	SD_UIMenu* getUIMenuSD(const std::string& name);
};

#endif