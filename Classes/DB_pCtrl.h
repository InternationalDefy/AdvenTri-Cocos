#ifndef __DB_PLAYER_CONTROLLER__
#define __DB_PLAYER_CONTROLLER__

#include "Ref_DataBase.h"

class SD_pCtrl;

using namespace cocos2d;

class DB_PlayerController :public DB
{
private:
	SD_pCtrl* tempSD;
	std::string tempName;

	Map<std::string, SD_pCtrl*> _table;
public:
	std::string useString(){ return "Table_PlayerController.csv"; }
	void getLine(const std::string& data);

	static DB_PlayerController* create();
	static DB_PlayerController* getInstance();

	SD_pCtrl* getPlayerControllerSD(const std::string& name);
};

#endif