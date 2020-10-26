#ifndef __MAP_ENVIR_BLAST__
#define __MAP_ENVIR_BLAST__

#include "cocos2d.h"
#include "M_ActionParser.h"

using namespace cocos2d;

class MAP_EnvirBlast :public M_ActionParser
{
private:
	void blast(Node*, float, float, const std::string&);
public:
	CREATE_ACTIONPARSER(MAP_EnvirBlast);
	FiniteTimeAction* getAction(Node*, std::vector<std::string>);
	FiniteTimeAction* getAction(Node*, Vector<String*>*);
};

#endif