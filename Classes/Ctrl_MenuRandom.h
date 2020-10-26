#ifndef __CTRL_MENURANDOM__
#define __CTRL_MENURANDOM__

#include "Ctrl_Base.h"
using namespace cocos2d;

class Ctrl_MenuRandom : public Ctrl_Base
{
private:
	float time;
	float limit;
	float velocity;
public:
	Ctrl_MenuRandom();
	CREATE_FUNC_CONTROLLER(Ctrl_MenuRandom);
	
	void initWithSD(SD_Ctrl* sd);
	void update(float dt);

};

#endif