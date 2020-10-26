#ifndef __DB_DIALOGUE__
#define __DB_DIALOGUE__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_Dialogue;

class DB_Dialogue : public DB
{
private:
	SD_Dialogue* tempSD;
	std::string tempName;

	Map<std::string, SD_Dialogue*> _table;
public:
	std::string useString(){ return "Table_Dialogue.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 12; }

	static DB_Dialogue* create();
	static DB_Dialogue* getInstance();

	SD_Dialogue* getDialogueSD(const std::string& name);
};

#endif