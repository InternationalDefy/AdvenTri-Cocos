#include "Ref2ActionHandler.h"

using namespace cocos2d;

void MAP_FadeOut::fadeOut(Node* node, float dt)
{
	node->runAction(FadeOut::create(dt));
	return;
}

FiniteTimeAction* MAP_FadeOut::getAction(Node* node, std::vector<std::string> params)
{
	float dt = std::atof(params.at(0).c_str());

	auto fadeE = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_FadeOut::fadeOut, this, node,dt)),
		DelayTime::create(dt));

	if (!fadeE)
	{
		log("stop");
	}
	return fadeE;
}
FiniteTimeAction* MAP_FadeOut::getAction(Node* node, Vector<String*>* param)
{
	float dt = std::atof(param->at(0)->getCString());

	auto fadeE = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_FadeOut::fadeOut, this, node, dt)),
		DelayTime::create(dt));

	if (!fadeE)
	{
		log("stop");
	}
	return fadeE;
}