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
Ctrl����������е��ж����⣬�ж�ʲôʱ�����ʲô�����⣬
��ָ���´ﵽStepAction��ʱ����ֻ����һ���£�doIt.
@param Entity* whom ��Ҫ������ʵ�塣
@param const std::string& what ����Ѱ�Ҷ�Ӧ��Parser��
@param void* how ��������һ�� !�������κ����ָ��! �Ĳ�������ʾ���ж��Ĳ�����
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
