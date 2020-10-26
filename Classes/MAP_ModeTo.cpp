#include "Ref2ActionHandler.h"

using namespace cocos2d;

void MAP_MoveTo::moveTo(Node* node, Vec2 pos2, float dt)
{
	node->runAction(Sequence::create(MoveTo::create(dt, pos2),
		CallFunc::create(std::bind(&MAP_MoveTo::setBack, this, node, node->getPosition())),
		NULL));
	return;
}
void MAP_MoveTo::setBack(Node* node, Vec2 pos2)
{
	node->setPosition(pos2);
	node->setVisible(FALSE);
	return;
}

FiniteTimeAction* MAP_MoveTo::getAction(Node* node, std::vector<std::string> param)
{
	float dt = std::atof(param.at(0).c_str());
	Vec2 pos2 = Vec2(std::atof(param.at(1).c_str()),
		std::atof(param.at(1).c_str()));

	auto Move2 = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_MoveTo::moveTo, this, node, pos2, dt)),
		DelayTime::create(dt));

	if (!Move2)
	{
		log("stop");
	}
	return Move2;
}
FiniteTimeAction* MAP_MoveTo::getAction(Node* node, Vector<String*>* param)
{
	float dt = std::atof(param->at(0)->getCString());
	Vec2 pos2 = Vec2(std::atof(param->at(1)->getCString()),
		std::atof(param->at(2)->getCString()));

	auto Move2 = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_MoveTo::moveTo, this, node, pos2, dt)),
		DelayTime::create(dt));

	if (!Move2)
	{
		log("stop");
	}
	return Move2;
}