#ifndef __SD_SKILL__
#define __SD_SKILL__

#include "cocos2d.h"
class M_ESshot;
class M_Enemy;

USING_NS_CC;

class SD_Eskill : public Ref
{
public:
	float _cooldown;
	std::string _positionName;
	std::string _type;
	std::vector<std::string> _params;
	void init();
public:
	static SD_Eskill* create();
	void addSkillsToEntity(M_Enemy* enemy);
};
#endif