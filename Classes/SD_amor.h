#ifndef __SD_AMOR__
#define __SD_AMOR__

#include "cocos2d.h"
#include "Ref_Enum.h"

USING_NS_CC;

class M_Enemy;

class SD_Amor : public Ref
{
public:
	int _defence;
	int _hp;
	AdvenTriEnum::AmorType _type;
	void init();
public:
	static SD_Amor* create();

	void addToEntity(M_Enemy* enemy);
};
#endif