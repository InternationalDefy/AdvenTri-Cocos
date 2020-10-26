#include "Ref2Controller.h"

using namespace cocos2d;

void DB_PlayerController::getLine(const std::string& data)
{
	tempSD = SD_pCtrl::create();
	tempName = analyseMiddle(data);
	tempSD->setForce(std::atof(analyseMiddle(data).c_str()));
	tempSD->setVangular(std::atof(analyseMiddle(data).c_str()));
	analyseEndln(data);
	_table.insert(tempName, tempSD);
}

SD_pCtrl* DB_PlayerController::getPlayerControllerSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "Player Ctrl_Base Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_PlayerController);