#ifndef __M_PSKILL__	
#define __M_PSKILL__

#include "cocos2d.h"

class SD_pSkill;
class M_Player;

using namespace cocos2d;

class M_pSkill : public Node
{
private:
	M_Player* _owner;

	float _coolDownTime;

public:
	virtual void active();

	float getCoolDown()
	{
		return _coolDownTime;
	}

	void initCoolDown(SD_pSkill* breed);

	void setOwner(M_Player* player);

	M_Player* getOwner();
};

#endif