#include "DB_ebreed.h"
#include "Ref_Entity.h"

USING_NS_CC;

void DB_EBreed::getLine(const std::string &data)
{
	tempBreed = SD_Ebreed::create();
	tempName = analyseMiddle(data);
	tempBreed->setTextureName(analyseMiddle(data));
	tempBreed->setAmorType(analyseMiddle(data));
	//对Skill的处理在Unit中实现，并将Skill添加到Entity中去
	tempBreed->setUnitType(analyseMiddle(data));
	tempBreed->setAnimationPack(analyseMiddle(data));
	tempBreed->setPhysicsBody(analyseMiddle(data));
	tempBreed->setWeaponType(analyseMiddle(data).c_str());
	tempBreed->setListenerSetName(analyseMiddle(data));
	tempBreed->setUiColID(std::atoi(analyseMiddle(data).c_str()));
	tempBreed->setController(analyseMiddle(data));
	analyseEndln(data);
	_ebreedTable.insert(tempName, tempBreed);
}

CREATE_DB(DB_EBreed);

M_Enemy* DB_EBreed::createEnemy(const std::string& name)
{
	if (!_ebreedTable.at(name))
	{
		std::string k = "Ebreed Name: " + name + " Unfound!";
		log(k.c_str());
	}
	else return _ebreedTable.at(name)->createFromEbreed();
}