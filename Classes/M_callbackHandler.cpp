#include "Ref2EventSystem.h"
#include "SD_callback.h"

using namespace cocos2d;

M_CallbackHandler* M_CallbackHandler::create()
{
	M_CallbackHandler* pRet = new(std::nothrow) M_CallbackHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_CallbackHandler* s_eventHandler;
M_CallbackHandler* M_CallbackHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_CallbackHandler::create();
	}
	return s_eventHandler;
}
void M_CallbackHandler::init()
{

}

M_CallbackParser* M_CallbackHandler::getCallbackWithStringData(SD_Callback* stringData)
{
	return handleDataType(stringData);
}

M_CallbackParser* M_CallbackHandler::handleDataType(SD_Callback* stringData)
{
	auto type = stringData->getCallbackFuncType();
	
	if (type == "CC_log")
	{
		//log("Assign PositionWithin!");
		return CP_TestLog::create(stringData);
	}
	if (type == "DiaCtrl_End")
	{
		return DCCP_DialogueEnd::create(stringData);
	}
	if (type == "LaCtrl_Left")
	{
		return DCCP_LaCtrlLeft::create(stringData);
	}
	if (type == "LaCtrl_Right")
	{
		return DCCP_LaCtrlRight::create(stringData);
	}
	log("CallbackFunc Type Name UNFOUND!");
	return NULL;
}