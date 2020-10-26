#include "Ref2Ebreed.h"

USING_NS_CC;

void M_Eskill::active(){}
/*
对技能的拓展在此！
*/
int M_Eskill::changeStringNameToType(const std::string& name)
{
	if (name == "Blade")
	{
		return 1;
	}
	if (name == "Dash")
	{
		return 6;
	}
	else
	{
		auto k = "Skill Type " + name + " UNFOUND!\n";
		log(k.c_str());
	}
}

M_Eskill* M_Eskill::create(SD_Eskill* breed)
{
	switch (M_Eskill::changeStringNameToType(breed->_type))
	{
	case 1:
		return M_ESshot::create(breed);
		break;
	case 6:
		return M_EDash::create(breed);
	default:
		break;
	}
}

M_Enemy* M_Eskill::getOwner()
{
	return _owner;
}

void M_Eskill::setOwner(M_Enemy* enemy)
{
	_owner = enemy;
}