#include "Ref2ActionHandler.h"

using namespace cocos2d;

FiniteTimeAction* M_ActionParser::getAction(Node*,std::vector<std::string>)
{
	log("This Method Shoundt be CALLED!");
	return NULL;
}

FiniteTimeAction* M_ActionParser::getAction(Node*,Vector<String*>*)
{
	log("This Method Shoundt be CALLED!");
	return NULL;
}