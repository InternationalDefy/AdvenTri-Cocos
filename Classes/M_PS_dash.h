#ifndef __M_PS_DASH__
#define __M_PS_DASH__

#include "cocos2d.h"
#include "M_pSkill.h"

class SD_pSkill;
class M_Player;

USING_NS_CC;

class M_PS_dash : public M_pSkill
{
private:
	float dashMulti;
private:
	Animate* animation;

	void init(SD_pSkill* breed);
public:
	static M_PS_dash* create(SD_pSkill* breed);

	void active();
};
#endif