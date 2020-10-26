#ifndef __M_ES_HSHOT__
#define __M_ES_HSHOT__

#include "cocos2d.h"
#include "M_Eskill.h"

class SD_Eskill;
class M_Enemy;

USING_NS_CC;

class M_ESshot : public M_Eskill
{
private:
	float _delay;
	Animate* animation;
	void init(SD_Eskill* breed);
public:
	static M_ESshot* create(SD_Eskill* breed);
	void active();
};
#endif