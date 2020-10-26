#ifndef __MAP_ENTITY_BLAST__
#define __MAP_ENTITY_BLAST__

#include "cocos2d.h"
#include "M_ActionParser.h"

using namespace cocos2d;

class MAP_EntityBlast :public M_ActionParser
{
private:
	void blast(Node*, float, float, const std::string&);
public:
	CREATE_ACTIONPARSER(MAP_EntityBlast);
	FiniteTimeAction* getAction(Node*, std::vector<std::string>);
	FiniteTimeAction* getAction(Node*, Vector<String*>*);
};

#endif