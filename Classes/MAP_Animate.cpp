#include "Ref2ActionHandler.h"

using namespace cocos2d;

FiniteTimeAction* MAP_Animate::getAction(Node* node,std::vector<std::string> params)
{
	Animate* ant = DB_Animate::getInstance()->getAnimate(params.at(0));
	if (!ant)
	{
		log("stop");
	}
	return ant;
}

FiniteTimeAction* MAP_Animate::getAction(Node* node, Vector<String*>* params)
{
	Animate* ant = DB_Animate::getInstance()->getAnimate(params->at(0)->getCString());
	if (!ant)
	{
		log("stop");
	}
	return ant;
}