#ifndef __M_PS_ATK__
#define __M_PS_ATK__

#include "cocos2d.h"
#include "M_pSkill.h"

class SD_pSkill;
class M_Player;

USING_NS_CC;

class M_PS_atk : public M_pSkill
{
private:
	Animate* animation;

	void init(SD_pSkill* breed);
public:
	static M_PS_atk* create(SD_pSkill* breed);

	void active();
};
#endif