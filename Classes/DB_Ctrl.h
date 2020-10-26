#ifndef __DB_CONTROLLER__
#define __DB_CONTROLLER__

#include "cocos2d.h"
#include "Ref_DataBase.h"

class SD_Ctrl;
class SD_Item;
class Ctrl_Base;

USING_NS_CC;

class DB_Ctrl : public DB
{
private:

	std::string tempName;
	SD_Ctrl* tempCStringData;
	SD_Item* tempIStringData;

	Map<std::string, SD_Ctrl*> _table;
	
public:
	
	std::string useString(){ return "Table_Controller.csv"; }
	void getLine(const std::string& data);
	int HeadLines(){ return 3; }

	static DB_Ctrl* create();
	static DB_Ctrl* getInstance();
	
	SD_Ctrl* getControllerSD(const std::string& name);
};

#endif