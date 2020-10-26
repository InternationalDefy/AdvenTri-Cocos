#include "Ref2Entity.h"
#include <tuple>

USING_NS_CC;

void Entity::update(float dt)
{
	for (auto i : _children)
	{
		i->update(dt);
	}
}
void Entity::destroy(){}
Entity* Entity::create(const std::string& filename)
{
	Entity *entity = new (std::nothrow) Entity();
	if (entity && entity->initWithFile(filename))
	{
		//Entity->setActionRunning(false);
		entity->initEntity();
		entity->autorelease();
		return entity;
	}
	CC_SAFE_DELETE(entity);
	return nullptr;
}
void Entity::setController(Ctrl_Base* controller)
{
	if (_controller)
	{
		_controller->removeFromParent();
	}
	_controller = controller;
	addChild(_controller);
	_controller->setEntity(this);
}
void Entity::setController(Ctrl_Player* pCtrl)
{
	if (_pCtrl)
	{
		_pCtrl->removeFromParent();
	}
	_pCtrl = pCtrl;
	addChild(_pCtrl);
	_pCtrl->setEntity(this);
}
void Entity::activeController()
{
	if (!_controller)
	{
		log("Entity's Ctrl_Base UNFOUND!");
		return;
	}
	_controller->active();
	return;
}
void Entity::activepCtrl()
{
	if (!_pCtrl)
	{
		log("Entity's Ctrl_Player UNFOUND!");
		return;
	}
	_pCtrl->active();
	return;
}
void Entity::addToScene(Layer* layer, int zOrder)
{
	layer->addChild(layer, zOrder);
	//log("stop");
}
void Entity::assignEventListener()
{
	for (auto i = 0; i < _callbackParser.size(); ++i)
	{
		_callbackParser.at(i)->assignListener();
	}
}
void Entity::initEntity()
{
	_controller = NULL;
	_pCtrl = NULL;
	_currentAnimation = NULL;
	_enableShadow = FALSE;
	_shadowSprite = NULL;
	EntityState = 0;
	EntityTAG = "";
}
Ctrl_Base* Entity::getController()
{
	return _controller;
}
Ctrl_Player* Entity::getpCtrl()
{
	return _pCtrl;
}
void Entity::pushDispatchParser(M_DispatchParser* dp)
{
	_dispatchParser.push_back(dp);
}
void Entity::pushCallbackParser(M_CallbackParser* cp)
{
	_callbackParser.push_back(cp);
}
void Entity::removeFromParent()
{
	auto k = _dispatchParser.size();
	for (auto i = 0; i < k; ++i)
	{
		Sys_Event::getInstance()->deleteDispatchFunc(_dispatchParser.at(i));
	}
	auto e = _callbackParser.size();
	for (auto i = 0; i < k; ++i)
	{
		Sys_Event::getInstance()->deleteCallbackFunc(_callbackParser.at(i));
	}
	Node::removeFromParent();
}
//以下处理Animation
void Entity::setAnimationPack(M_AnimationPack* animationPack)
{
	if (_animationPack)
		_animationPack = NULL;
	_animationPack = animationPack;
	_animationPack->retain();
}
void Entity::runAnimation(const std::string& key)
{
	if (_currentAnimation&&_animationRunning)
	{
		stopAction(_currentAnimation);
	}

	FiniteTimeAction* act;	
	try {
		act = _animationPack->getAnimation(key);
	}
	catch (std::exception e)
	{
		log(("Entity's Animation " + key + " UNFOUD!").c_str());
	}
	_animationRunning = TRUE;
	_currentAnimation = act;
	runAction(Sequence::create(act,
		CallFunc::create(CC_CALLBACK_0(Entity::animationEndCallback, this)), NULL));
return;
}
void Entity::animationEndCallback()
{
	_animationRunning = FALSE;
}
//以下处理Shadow
M_Shadow* Entity::getShadow()
{
	if (_enableShadow)
		return _shadowSprite;
	else
		log("Cant Get");
		return NULL;
}
void Entity::setShadow(float height, float depth)
{
	M_Shadow* sp = M_Shadow::createWithTexture(_texture);
	float ratio = (height + depth) / height;

	sp->setHeight(height);
	sp->setDepth(depth);
	sp->setEntity(this);

	sp->setScale(ratio);

	sp->setAnchorPoint(Vec2(	0.5f,0.5f));

	sp->setPosition(Vec2(
		getContentSize().width*0.5f,
		getContentSize().height*0.5f));

	addChild(sp,  -1);

	sp->setColor(Color3B(0, 0, 0));
	sp->setOpacity(127);
	
	_shadowSprite = sp;
	_enableShadow = TRUE;
	return;
}
