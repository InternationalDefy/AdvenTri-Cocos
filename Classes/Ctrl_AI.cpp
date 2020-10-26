#include "Ref2Controller.h"

Ctrl_AI::Ctrl_AI()
{
	fDelayCount = 0.0f;
	fLimitTime = 0.0f;
	bFrozen = FALSE;
	bCursed = FALSE;
	ptnEnemy = NULL;
}

Vec2 Ctrl_AI::getTargetVec2()
{
	log("cant!");
	return Vec2(0, 0);
}

Vec2 Ctrl_AI::getDashVec2()
{
	log("cant!");
	return Vec2(0, 0);
}
void Ctrl_AI::update(float dt)
{
	log("Shount! be Called!");
}

void Ctrl_AI::initWithSD(SD_Ctrl* sd)
{
	fLimitTime = sd->getDelta();
	return;
}

bool Ctrl_AI::updateTime(float dt)
{
	if (bFrozen)
		fDelayCount -= 0.5f*dt;
	fDelayCount += dt;
	if (fDelayCount > fLimitTime)
	{
		fDelayCount = 0.0f;
		return TRUE;
	}
}

Node* Ctrl_AI::getEnemeyTarget()
{
	if (!ptnEnemy)
	{
		log("Nope!");
		return NULL;
	}
	return ptnEnemy;
}
void Ctrl_AI::setFrozen() 
{
	bFrozen = TRUE;
}
void Ctrl_AI::setCursed()
{
	bCursed = TRUE;
}
void Ctrl_AI::setUnFrozen() 
{
	bFrozen = FALSE;
}
void Ctrl_AI::setUnCursed() 
{
	bCursed = FALSE;
}