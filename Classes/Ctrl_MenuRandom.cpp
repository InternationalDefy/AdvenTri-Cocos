#include "Ref2Controller.h"
Ctrl_MenuRandom::Ctrl_MenuRandom()
{
	time = 0;
	limit = 0;
	velocity = 0;
}
void Ctrl_MenuRandom::initWithSD(SD_Ctrl* sd)
{
	time = std::atof(sd->getLines()->at(0)->getStrings()->at(0)->getCString());
	limit = std::atof(sd->getLines()->at(0)->getStrings()->at(1)->getCString());
	velocity = std::atof(sd->getLines()->at(0)->getStrings()->at(2)->getCString());
	time = 0.6f*time + 0.8f*rand_0_1()*time;
	limit = 0.6f*limit + 0.8f*rand_0_1()*limit;
	velocity = 0.6f*velocity + 0.8f*rand_0_1()*velocity;
}
void Ctrl_MenuRandom::update(float dt)
{
	time += dt;
	if (time > limit)
	{
		getEntity()->getPhysicsBody()->setVelocity(Vec2(
			(CCRANDOM_0_1() - 0.5f)*2.0f*velocity, (CCRANDOM_0_1() - 0.5f)*2.0f*velocity));
		time = 0.0f ;
	}
}