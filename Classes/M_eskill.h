#ifndef __M_ESKILL__	
#define __M_ESKILL__

#include "cocos2d.h"

class SD_Eskill;
class M_Enemy;

using namespace cocos2d;

class M_Eskill	: public Ref
{
private:
	M_Enemy* _owner;
	static int changeStringNameToType(const std::string& name);
	//void parseType()?不确定是否需要
public:
	virtual void active();
	static M_Eskill* create(SD_Eskill* breed);
	void setOwner(M_Enemy* enemy);
	M_Enemy* getOwner();
};

#endif