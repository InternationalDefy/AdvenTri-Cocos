#include "Ref2ActionHandler.h"

using namespace cocos2d;

void MAP_FadeIn::fadeIn(Node* node, float dt)
{
	node->setOpacity(0);
	node->setVisible(true);
	node->runAction(FadeIn::create(dt));
	return;
}

FiniteTimeAction* MAP_FadeIn::getAction(Node* node,std::vector<std::string> params)
{
	float dt = std::atof(params.at(0).c_str());

	auto fadeE = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_FadeIn::fadeIn, this, node, dt)),
		DelayTime::create(dt));

	if (!fadeE)
	{
		log("stop");
	}
	return fadeE;
}
FiniteTimeAction* MAP_FadeIn::getAction(Node* node,Vector<String*>* param)
{
	float dt = std::atof(param->at(0)->getCString());

	auto fadeE = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_FadeIn::fadeIn, this, node, dt)),
		DelayTime::create(dt));

	if (!fadeE)
	{
		log("stop");
	}
	return fadeE;
}