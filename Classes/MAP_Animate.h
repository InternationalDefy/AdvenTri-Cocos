#ifndef __MAP_ANIMATE__
#define __MAP_ANIMATE__

#include "cocos2d.h"
#include "M_ActionParser.h"

using namespace cocos2d;

class MAP_Animate :public M_ActionParser
{
public:
	CREATE_ACTIONPARSER(MAP_Animate);
	FiniteTimeAction* getAction(Node*, std::vector<std::string>);
	FiniteTimeAction* getAction(Node*, Vector<String*>*);
};

#endif