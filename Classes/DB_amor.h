#ifndef __DB_AMOR__
#define __DB_AMOR__

#include "cocos2d.h"

#include "DataBase.h"

class SD_Amor;
class M_Enemy;

USING_NS_CC;

class DB_Amor: public DB
{
private:

	SD_Amor* tempBreed;
	std::string tempName;

	Map<std::string,SD_Amor*> _amorTable;
	
public:

	void getLine(const std::string& data);
	std::string useString(){ return "Table_Amor.csv"; }

	void addAmorToEntity(const std::string& name, M_Enemy* ennemy);

	static DB_Amor* create();
	static DB_Amor* getInstance();
	
};

#endif