#ifndef __MAP_FADEIN__
#define __MAP_FADEIN__

#include "cocos2d.h"
#include "M_ActionParser.h"

using namespace cocos2d;

class MAP_FadeIn :public M_ActionParser
{
private:
	void fadeIn(Node*, float);
public:
	CREATE_ACTIONPARSER(MAP_FadeIn);
	FiniteTimeAction* getAction(Node*, std::vector<std::string>);
	FiniteTimeAction* getAction(Node*, Vector<String*>*);
};

#endif