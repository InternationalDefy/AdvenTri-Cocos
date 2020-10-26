#include "Ref2EnemyState.h"

using namespace cocos2d;

void M_EnemyState::enterFrom(M_EnemyState* stateFrom)
{
	log("This State Method Shouldnt be called!");
	return;
}

void M_EnemyState::exitTo(M_EnemyState* stateTo)
{
	log("This State Method Shouldnt be called!");
	return;
}
void M_EnemyState::exitToStandred()
{
	auto standredState = ES_Standred::create();
	exitTo(standredState);
}
void M_EnemyState::exitToUse()
{}
void M_EnemyState::exitToGather(int type)
{
}
void M_EnemyState::exitToDash()
{
	auto dashState = ES_Dash::create();
	exitTo(dashState);
}
void M_EnemyState::exitToOperate()
{}

void M_EnemyState::handleAction(AdvenTriEnum::EnemyAction action)
{
	log("This State Method Shouldnt be called!");
	return;
}
void M_EnemyState::initState()
{
	_clockTime = 0;
	_limitTime = 0;
	_state = AdvenTriEnum::EnemyState::E_STATE_STANDRED;
	//	log("This State Method Shouldnt be called!");
	return;
}
void M_EnemyState::updateMethod(float dt)
{
	log("This State Method Shouldnt be called!");
	return;
}

/*
void M_EnemyState::setClockAction(Action* action)
{
_clockAction = action;
return;
}
Action* M_EnemyState::getClockAction()
{
if (!_clockAction)
{
log("Aint Any Clock Action!");
return NULL;
}
return _clockAction;
}
*/

void CALLBACK M_EnemyState::updateFar(float dt)
{
	this->retain();
	_clockTime += dt;
	if (_clockTime > _limitTime)
	{
		this->exitTo(ES_Standred::create());
		return;
	}
	this->updateMethod(dt);
	return;
}

M_Enemy* M_EnemyState::getOwner()
{
	if (_owner)
	{
		return _owner;
	}
	else
	{
		log("No Owner To get!");
		return NULL;
	}
}
void M_EnemyState::setOwner(M_Enemy* enemy)
{
	_owner = enemy;
	this->retain();
}

CREATE_ENEMYSTATE(M_EnemyState);