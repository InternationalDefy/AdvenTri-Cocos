#include "Ref2Controller.h"

USING_NS_CC;
Ctrl_Base::Ctrl_Base()
{
	_actived = FALSE;
	_entity = NULL;
	return;
}

void Ctrl_Base::active()
{
	_entity->addChild(this);
	return;
}
void Ctrl_Base::deActive()
{
	_actived = FALSE;
	_parent->removeChild(this);
	this->retain();
	return;
}
bool Ctrl_Base::isActive()
{
	return _actived;
}
Entity* Ctrl_Base::getEntity()
{
	return _entity;
}
void Ctrl_Base::setEntity(Entity* entity)
{
	_entity = entity;
	this->retain();
}

void Ctrl_Base::initWithSD(SD_Ctrl* controllerStringData)
{
	log("Shount be Accomplised with Child Class!");
}
void Ctrl_Base::update(float dt)
{
	log("Shount be Accomplised with Child Class!");
}
void Ctrl_Base::setFrozen()
{
	log("Shount be Accomplised with Child Class!");
}
void Ctrl_Base::setCursed()
{
	log("Shount be Accomplised with Child Class!");
}
void Ctrl_Base::setUnFrozen()
{
	log("Shount be Accomplised with Child Class!");
}
void Ctrl_Base::setUnCursed()
{
	log("Shount be Accomplised with Child Class!");
}
void Ctrl_Base::assignListener()
{
	log("Shount be Accomplised with Child Class!");
}
Vec2 Ctrl_Base::getDashVec2()
{
	log("Shount be Accomplised with Child Class!");
	return Vec2(0, 0);
}
Vec2 Ctrl_Base::getTargetVec2()
{
	log("Shount be Accomplised with Child Class!");
	return Vec2(0, 0);
}