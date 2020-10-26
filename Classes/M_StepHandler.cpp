#include "Ref2Controller.h"

using namespace cocos2d;

M_StepHandler* M_StepHandler::create()
{
	M_StepHandler* pRet = new(std::nothrow)M_StepHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
M_StepHandler* s_ActionHandler;
M_StepHandler* M_StepHandler::getInstance()
{
	if (!s_ActionHandler)
	{
		s_ActionHandler = M_StepHandler::create();
	}
	return s_ActionHandler;
}

void M_StepHandler::init()
{
	smpStepParser.insert(std::make_pair("None", M_StepParser::create()));
	return;
}
/*
Ctrl处理控制器中的判断问题，判断什么时候该做什么的问题，
当指令下达到StepAction的时候，它只考虑一件事，doIt.
@param Entity* whom 所要操作的实体。
@param const std::string& what 用来寻找对应的Parser。
@param void* how 用来传递一个 !可以是任何类的指针! 的参数，表示该行动的参数。
*/
void M_StepHandler::runStep(Entity* whom, const std::string& what, void* how)
{
	M_StepParser* pas;
	try {
		pas = smpStepParser.at(what);
	}
	catch (std::exception& e)
	{
		log("nope!");
	}
	pas->doIt(whom, how);
}
