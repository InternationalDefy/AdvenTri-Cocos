#ifndef __SD_UBREED__
#define __SD_UBREED__

#include "cocos2d.h"

class SD_Eskill;
class M_Enemy;

USING_NS_CC;

class M_Enemy;

class SD_Ubreed : public Ref
{
public:
	Vector<SD_Eskill*> _skill_data;
	void init();
public:
	static SD_Ubreed* create();

	void addToEntity(M_Enemy* enemy);
};
#endif