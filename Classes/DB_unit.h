#ifndef __DB_UNIT__
#define __DB_UNIT__

#include "cocos2d.h"

#include "DataBase.h"

class SD_Ubreed;
class M_Enemy;

USING_NS_CC;

class DB_Unit: public DB
{
private:

	SD_Ubreed* tempBreed;
	std::string tempName;
	//std::string tempType;

	Map<std::string,SD_Ubreed*> _breedTable;
	
public:

	void getLine(const std::string& data);
	std::string useString(){ return "Table_Unit.csv"; };
	
	static DB_Unit* getInstance();
	static DB_Unit* create();

	void handleUnitType(const std::string& name,M_Enemy* enemy);
};

#endif