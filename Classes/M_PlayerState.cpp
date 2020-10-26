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
void M_PlayerState::exitToStandred()
{
	auto standredState = PS_Standred::create();
	exitTo(standredState);
}
void M_PlayerState::exitToUse()
{}
void M_PlayerState::exitToGather(int type)
{
}
void M_PlayerState::exitToDash()
{
	auto dashState = PS_Dash::create();
	exitTo(dashState);
}
void M_PlayerState::exitToOperate()
{}

void M_PlayerState::handleAction(AdvenTriEnum::PlayerAction action)
{
	log("This State Method Shouldnt be called!");
	return;
}
void M_PlayerState::initState()
{
	_clockTime = 0;
	_limitTime = 0;
	_state = AdvenTriEnum::PlayerStateType::P_STATE_STANDRED;
	//	log("This State Method Shouldnt be called!");
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

void CALLBACK M_PlayerState::updateFar(float dt)
{
	this->retain();
	_clockTime += dt;
	if (_clockTime > _limitTime)
	{
		this->exitTo(PS_Standred::create());
		return;
	}
	this->updateMethod(dt);
	return;
}

M_Player* M_PlayerState::getPlayer()
{
	if (_player)
	{
		return _player;
	}
	else
	{
		log("No Player To get!");
		return NULL;
	}
}
void M_PlayerState::setPlayer(M_Player* player)
{
	_player = player;
	this->retain();
}
CREATE_PLAYERSTATE(M_PlayerState);