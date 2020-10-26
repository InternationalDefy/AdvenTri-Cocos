#include "Ref2ActionHandler.h"

using namespace cocos2d;

void MAP_EnvirBlast::blast(Node* node, float dt, float multi, const std::string& img)
{
	auto layer = node->getLayer();
	auto patc = ParticleExplosion::create();
	patc->initWithTotalParticles(multi);
	
	patc->setTexture(Director::getInstance()->getTextureCache()->addImage(img));
	patc->setDuration(dt);
	patc->setLife(2.0f);
	patc->setLifeVar(0.3f);
	patc->setStartColor(Color4F(255, 255, 255, 255));
	patc->setStartColorVar(Color4F(0, 0, 0, 0));
	patc->setEndColor(Color4F(255, 255, 255, 255));
	patc->setEndColorVar(Color4F(0, 0, 0, 0));
	patc->setStartSize(64.0f);
	patc->setStartSizeVar(2.0f);
	patc->setEndSize(64.0f);
	patc->setEndSizeVar(12.0f);
	patc->setEmissionRate(multi / dt);

	patc->setPosition(node->getPosition());
	
	layer->addChild(patc, node->getLocalZOrder() + 1);
	
	return;
}


FiniteTimeAction* MAP_EnvirBlast::getAction(Node* node, std::vector<std::string> params)
{
	float dt = std::atof(params.at(1).c_str());
	float multi = std::atof(params.at(2).c_str());
	std::string img = params.at(0);

	auto blasT = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_EnvirBlast::blast, this, node, dt, multi, img)),
		DelayTime::create(dt));

	if (!blasT)
	{
		log("stop");
	}
	return blasT;
}
FiniteTimeAction* MAP_EnvirBlast::getAction(Node* node, Vector<String*>* param)
{
	float dt = std::atof(param->at(1)->getCString());
	float multi = std::atof(param->at(2)->getCString());
	std::string img = param->at(0)->getCString();

	auto blasT = Spawn::createWithTwoActions(
		CallFunc::create(std::bind(&MAP_EnvirBlast::blast, this, node, dt, multi, img)),
		DelayTime::create(dt));

	if (!blasT)
	{
		log("stop");
	}
	return blasT;
}