#include "Ref2EventSystem.h"
#include "SD_callback.h"

using namespace cocos2d;
/*
M_CallbackParser* M_CallbackParser::create(SD_Callbacker* stringData)
{
M_CallbackParser* pRet = new(std::nothrow) M_CallbackParser();
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
CREATE_CALLBACKPARSER(M_CallbackParser);

void M_CallbackParser::initWithStringData(SD_Callback* stringData)
{
	return;
}
void M_CallbackParser::onCustomEvent(EventCustom* eventCustom)
{
	log("TestEventRecivied!");
	return;
}
void M_CallbackParser::initLimit(SD_Callback* stringData)
{
	_proximity = stringData->getFixedProximity();
	_coolDownTime = stringData->getCoolDownTime();
	_limitTimes = stringData->getLimitedTimes();
}
void M_CallbackParser::cooldownEndCallback()
{
	if (_limitTimes)
	{
		_listener->setEnabled(TRUE);
		return;
	}
	removeSelf();
	return;
}
void M_CallbackParser::updateLimit()
{
	if (_limitTimes)
	{
		_limitTimes -= 1;
	}
	_listener->setEnabled(FALSE);
	runAction(Sequence::create(DelayTime::create(_coolDownTime),
		CallFunc::create(CC_CALLBACK_0(M_CallbackParser::cooldownEndCallback, this)), NULL));
	return;
}
void M_CallbackParser::setSystem(Sys_Event* sys)
{
	_system = sys;
}
void M_CallbackParser::removeSelf()
{
	if (!_system)
	{
		log("NO!!!!!!");
		return;
	}
	_system->deleteCallbackFunc(this);
}
void M_CallbackParser::removeListener()
{
	_eventDispatcher->removeEventListener(_listener);
}
void M_CallbackParser::assignListener()
{
	auto lis = EventListenerTouchOneByOne::create();
	lis->setSwallowTouches(true);
	_listener = EventListenerCustom::create(
		_stringData->getUprecivingEventName(),
		CC_CALLBACK_1(M_CallbackParser::onCustomEvent, this));
	if (_proximity == -1)
	{
		_pNode->getEventDispatcher()->addEventListenerWithSceneGraphPriority(_listener, _pNode);
		return;
	}
	else
	{
		_pNode->getEventDispatcher()->addEventListenerWithFixedPriority(_listener, _proximity);
		return;
	}
}

void M_CallbackParser::initEventName(SD_Callback* stringData)
{
	_eventName = stringData->getUprecivingEventName();
	return;
}
std::string M_CallbackParser::getEventName()
{
	return _eventName;
}
void M_CallbackParser::setParentNode(Node* pNode)
{
	_pNode = pNode;
	pNode->addChild(this);
	this->assignListener();
	return;
}
Node* M_CallbackParser::getParentNode()
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
