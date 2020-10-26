#include "Ref2Ebreed.h"

USING_NS_CC;

void DB_Weapon::getLine(const std::string &data)
{
	tempBreed = SD_Wbreed::create();
	tempName = analyseMiddle(data);
	tempBreed->_physics_body_name = analyseMiddle(data);
	tempBreed->_textureName = analyseMiddle(data);
	tempBreed->_broken_animation_name = analyseMiddle(data);
	tempBreed->_damageType = AdvenTriEnum::changeStringToDamageType(analyseMiddle(data));
	tempBreed->_damage = std::atoi(analyseMiddle(data).c_str());
	analyseEndln(data);
	_weaponTable.insert(tempName,tempBreed);
}

CREATE_DB(DB_Weapon);

void DB_Weapon::addWeaponToEnemy(const std::string& key,M_Enemy* enemy)
{
	if (_weaponTable.at(key))
	{ 
		return _weaponTable.at(key)->addToEntity(enemy); 
	}
	else
	{
		auto k = "Weapon Name :" + key + " UNFOUND!";
		log(k.c_str());
	}
}