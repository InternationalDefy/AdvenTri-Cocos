#include "Ref2EventSystem.h"
#include "SD_dispatcher.h"

using namespace cocos2d;
/*
M_DispatchParser* M_DispatchParser::create(SD_Dispatcher* stringData)
{
	M_DispatchParser* pRet = new(std::nothrow) M_DispatchParser();
	if (pRet&&pRet->init())
	{
		pRet->autorelease();
		pRet->initWithStringData(stringData);
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
*/
CREATE_DISPATCHPARSER(M_DispatchParser);

void M_DispatchParser::initWithStringData(SD_Dispatcher* stringData)
{
	return;
}
void M_DispatchParser::update(float dt)
{
	return;
}

void M_DispatchParser::removeSelf()
{
	if (!_system)
	{
		log("No!!!!!!");
		return;
	}
	_system->deleteDispatchFunc(this);
	return;
}

void M_DispatchParser::cooldownEndCallback()
{
	if (_limitTimes)
	{
		_locked = FALSE;
		return;
	}
	removeSelf();
	return;
}
void M_DispatchParser::updateLimit()
{
	if (_limitTimes)
	{
		_limitTimes -= 1;
	}
	_locked = TRUE;
	runAction(Sequence::create(DelayTime::create(_coolDownTime),
		CallFunc::create(CC_CALLBACK_0(M_DispatchParser::cooldownEndCallback, this)), NULL));
	return;
}
void M_DispatchParser::initLimit(SD_Dispatcher* stringData)
{
	_locked = FALSE;
	_limitTimes = stringData->getLimitTimes();
	_coolDownTime = stringData->getCooldownTime();
}
void M_DispatchParser::setSystem(Sys_Event* sys)
{
	_system = sys;
}
void M_DispatchParser::initEventName(SD_Dispatcher* stringData)
{
	_eventName = stringData->getUpsendingEventName();
	return;
}
std::string M_DispatchParser::getEventName()
{
	return _eventName;
}
void M_DispatchParser::setParentNode(Node* pNode)
{
	_pNode = pNode;
	pNode->addChild(this);
	return;
}
Node* M_DispatchParser::getParentNode()
{
	if (_pNode)
	{
		return _pNode;
	}
	else
	{
		log("aint a Parent Node!");
		return NULL;
	}
}