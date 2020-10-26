#ifndef __M_ES_DASH__
#define __M_ES_DASH__

#include "cocos2d.h"
#include "M_Eskill.h"

class SD_Eskill;
class M_Enemy;

USING_NS_CC;

class M_EDash : public M_Eskill
{
private:
	float _imp;
	Animate* animation;
	void init(SD_Eskill* breed);
public:
	static M_EDash* create(SD_Eskill* breed);
	void active();
};
#endif