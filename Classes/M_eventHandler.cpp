#include "Ref2EventSystem.h"
#include "SD_event.h"


using namespace cocos2d;

M_EventHandler* M_EventHandler::create()
{
	M_EventHandler* pRet = new(std::nothrow) M_EventHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

M_EventHandler* s_eventHandler;

M_EventHandler* M_EventHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_EventHandler::create();
	}
	return s_eventHandler;
}
void M_EventHandler::init()
{

}

EventCustom M_EventHandler::getEventFromStringData(SD_Event* stringData, const std::string& name)
{
	EventCustom ev(name);
	handleDataType(&ev, stringData);
	return ev;
}

void M_EventHandler::handleDataType(EventCustom* eventCustom, SD_Event* stringData)
{
	auto type = stringData->getParamType();
	if (type == "int")
	{
		auto param = std::atoi(stringData->getParam().c_str());
		eventCustom->setUserData(&param);
		return;
	}
	else if (type == "float")
	{
		auto param = std::atof(stringData->getParam().c_str());
		eventCustom->setUserData(&param);
		return;
	}
	else if (type == "string")
	{
		auto param = stringData->getParam();
		eventCustom->setUserData(&param);
		return;
	}
	else
	{
		log("Event Type Name UNFOUND!");
		return;
	}
}