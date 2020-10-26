#ifndef __DB_WEAPON__
#define __DB_WEAPON__

#include "cocos2d.h"

#include "DataBase.h"

class M_Enemy;
class SD_Wbreed;

USING_NS_CC;

class DB_Weapon: public DB
{
private:
	SD_Wbreed* tempBreed;

	std::string tempName;
	
	Map<std::string, SD_Wbreed*> _weaponTable;
public:

	void getLine(const std::string& data);
	std::string useString(){ return "Table_Weapon.csv"; }

	SD_Wbreed* getWeaponData(const std::string& key);
	void addWeaponToEnemy(const std::string& key, M_Enemy* enemy);

	static DB_Weapon* create();
	static DB_Weapon* getInstance();

	
};

#endif