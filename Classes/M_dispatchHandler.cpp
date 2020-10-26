#include "Ref2EventSystem.h"
#include "SD_dispatcher.h"

using namespace cocos2d;

M_DispatchHandler* M_DispatchHandler::create()
{
	M_DispatchHandler* pRet = new(std::nothrow) M_DispatchHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_DispatchHandler* s_eventHandler;
M_DispatchHandler* M_DispatchHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_DispatchHandler::create();
	}
	return s_eventHandler;
}
void M_DispatchHandler::init()
{

}
/*
void M_DispatchHandler::addDispatcherWithStringData(SD_Dispatcher* stringData)
{
	handleDataType(pNode, stringData);
}
*/
M_DispatchParser* M_DispatchHandler::getDispatcherWithStringData(SD_Dispatcher* stringData)
{
	return handleDataType(stringData);
}

M_DispatchParser* M_DispatchHandler::handleDataType(SD_Dispatcher* stringData)
{
	auto type = stringData->getListeningFuncType();
	if (type == "PositionWithin")
	{
		//log("Assign PositionWithin!");
		return DP_PositionWithin::create(stringData);
	}
	if (type == "LeftClickOnThis")
	{
		return DP_LeftClickOnThis::create(stringData);
	}
	if (type == "LeftClickOnUIItem")
	{
		return DP_LeftClickOnUIItem::create(stringData);
	}
	log("ListeningFunc Type Name UNFOUND!");
	return NULL;
}