#ifndef __MAP_MOVETO__
#define __MAP_MOVETO__

#include "cocos2d.h"
#include "M_ActionParser.h"

using namespace cocos2d;

class MAP_MoveTo :public M_ActionParser
{
private:
	void setBack(Node*, Vec2);
	void moveTo(Node*, Vec2, float);
public:
	CREATE_ACTIONPARSER(MAP_MoveTo);
	FiniteTimeAction* getAction(Node*, std::vector<std::string>);
	FiniteTimeAction* getAction(Node*, Vector<String*>*);
};

#endif