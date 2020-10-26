#ifndef __M_STEPHANDLER__
#define __M_STEPHANDLER__

#include "cocos2d.h"

using namespace cocos2d;

class M_StepParser;
class Entity;

class M_StepHandler :public Ref
{
private:
	static M_StepHandler* create();
	void init();
	std::map<std::string, M_StepParser*> smpStepParser;
public:
	static M_StepHandler* getInstance();
	/*
	Ctrl处理控制器中的判断问题，判断什么时候该做什么的问题，
	当指令下达到StepAction的时候，它只考虑一件事，doIt.
	@param Entity* whom 所要操作的实体。
	@param const std::string& what 用来寻找对应的Parser。
	@param void* how 用来传递一个 !可以是任何类的指针! 的参数，表示该行动的参数。
	*/
	void runStep(Entity* whom, const std::string& what, void* how);
};

#endif