#include "Ref2ActionHandler.h"

using namespace cocos2d;

M_ActionHandler* M_ActionHandler::create()
{
	M_ActionHandler* pRet = new(std::nothrow)M_ActionHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
M_ActionHandler* s_ActionHandler;
M_ActionHandler* M_ActionHandler::getInstance()
{
	if (!s_ActionHandler)
	{
		s_ActionHandler = M_ActionHandler::create();
	}
	return s_ActionHandler;
}

void M_ActionHandler::init()
{
	_actionParsers.insert(std::make_pair("FadeIn", MAP_FadeIn::create()));
	_actionParsers.insert(std::make_pair("Animate", MAP_Animate::create()));
	_actionParsers.insert(std::make_pair("MoveTo", MAP_MoveTo::create()));
	_actionParsers.insert(std::make_pair("FadeOut", MAP_FadeOut::create()));
	_actionParsers.insert(std::make_pair("EnvirBlast", MAP_EnvirBlast::create()));
	_actionParsers.insert(std::make_pair("EntityBlast", MAP_EntityBlast::create()));
	return;
}

void M_ActionHandler::runEnvirAction(Node* pNode, Vec3 position, int localZ, const std::string& animationName)
{
	auto node = Node::create();
	pNode->addChild(node,localZ);
	node->setPosition3D(position);
	FiniteTimeAction* act = getAction(node, animationName);
	node->runAction(act);
}

void M_ActionHandler::addAnimationPackToEntity(Entity* entity,const std::string& packname)
{
	M_AnimationPack* pack = M_AnimationPack::create();
	SD_AnimationPack* sd = DB_AnimationPack::getInstance()->getAnimationPackSD(packname);
	for (auto i = sd->getKeyMap()->begin(); i != sd->getKeyMap()->end(); ++i)
	{
		auto key = i->first;
		auto name = i->second;
		auto anim = getAction(entity, name);
		pack->addAnimation(key, anim);
	}
	entity->setAnimationPack(pack);
}


FiniteTimeAction* M_ActionHandler::getAction(Node* node, const std::string& animationName)
{
	auto sd = DB_Animation::getInstance()->getAnimationSD(animationName);
	auto t = sd->getAnimationTypeName();
	auto param = sd->getParamPointer();
	return getAction(node, t, *param);
}

FiniteTimeAction* M_ActionHandler::getAction(Node* node,const std::string& type, std::vector<std::string> param)
{
	M_ActionParser* pas;
	try {
		pas = _actionParsers.at(type);
	}
	catch (std::exception& e)
	{
		log("nope!");
	}
	auto act = pas->getAction(node,param);
	return act;
}

FiniteTimeAction* M_ActionHandler::getAction(Node* node,const std::string& type, Vector<String*>* param)
{
	M_ActionParser* pas;
	try {
		pas = _actionParsers.at(type);
	}
	catch (std::exception& e)
	{
		log("nope!");
	}
	auto act = pas->getAction(node,param);
	return act;
}