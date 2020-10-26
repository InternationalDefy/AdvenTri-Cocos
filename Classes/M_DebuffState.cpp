#include "Ref2PlayerState.h"

using namespace cocos2d;

void M_PlayerState::enterFrom(M_PlayerState* stateFrom)
{
	log("This State Method Shouldnt be called!");
	return;
}

void M_PlayerState::exitTo(M_PlayerState* stateTo)
{
	log("This State Method Shouldnt be called!");
	return;
}

void M_PlayerState::handleAction(AdvenTriEnum::PlayerAction action)
{
	log("This State Method Shouldnt be called!");
	return;
}

void M_PlayerState::initState()
{
	_clockTime = 0;
	_limitTime = 0;
	_stateTag = 0;
	//	log("This State Method Shouldnt be called!");
	return;
}

void M_PlayerState::update(float dt)
{
	_clockTime += dt;
	if (_clockTime > _limitTime)
	{
		this->exitTo(PS_Standred::create());
		return;
	}
	this->updateMethod(dt);
	return;
}

void M_PlayerState::updateMethod(float dt)
{
	log("This State Method Shouldnt be called!");
	return;
}

/*
void M_PlayerState::setClockAction(Action* action)
{
_clockAction = action;
return;
}
Action* M_PlayerState::getClockAction()
{
if (!_clockAction)
{
log("Aint Any Clock Action!");
return NULL;
}
return _clockAction;
}
*/
M_Player* M_PlayerState::getPlayer()
{
	if (getParent())
	{
		return dynamic_cast<M_Player*> (getParent());
	}
	else
	{
		log("No Parent To get!");
		return NULL;
	}
}
CREATE_PLAYERSTATE(M_PlayerState);