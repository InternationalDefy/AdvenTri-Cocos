#ifndef __DB_DIALOG__
#define __DB_DIALOG__

#include "Ref_DataBase.h"

class SD_Dialog;

using namespace cocos2d;

class DB_Dialog :public DB
{
private:
	SD_Dialog* tempSD;
	std::string tempName;

	Map<std::string, SD_Dialog*> _table;
public:
	std::string useString(){ return "Table_Dialog.csv"; }
	void getLine(const std::string& data);

	static DB_Dialog* create();
	static DB_Dialog* getInstance();

	SD_Dialog* getDialogSD(const std::string& name);
};

#endif