#ifndef __DB_EBREED__
#define __DB_EBREED__

#include "cocos2d.h"

#include "SD_Ebreed.h"
#include "DataBase.h"

class M_Enemy;

USING_NS_CC;

class DB_EBreed: public DB
{
private:
	SD_Ebreed* tempBreed;

	std::string tempName;
	std::string tempKey;
	std::string tempAnimateName;

	Map<std::string, SD_Ebreed*> _ebreedTable;
	
public:

	void getLine(const std::string& data);
	std::string useString(){ return "Table_Ebreed.csv"; }

	static DB_EBreed* create();
	static DB_EBreed* getInstance();

	M_Enemy* createEnemy(const std::string& name);
	
};

#endif