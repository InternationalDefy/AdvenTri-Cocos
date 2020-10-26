#include "Ref2EventSystem.h"
#include "SD_dispatcher.h"

using namespace cocos2d;

CREATE_DISPATCHPARSER(DP_LeftClickOnThis);

void DP_LeftClickOnThis::initWithStringData(SD_Dispatcher* stringData)
{
	return;
}

void DP_LeftClickOnThis::setParentNode(Node* parent)
{
	M_DispatchParser::setParentNode(parent);
	auto lis = EventListenerMouse::create();
	lis->onMouseDown = CC_CALLBACK_1(DP_LeftClickOnThis::onMouseDownCallback, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis, parent);
}

void DP_LeftClickOnThis::onMouseDownCallback(Event* event)
{
	auto eventMouse = (EventMouse*)event;
	auto pos = Vec2(eventMouse->getCursorX(),
		eventMouse->getCursorY());
	if ((Sprite*)getParent()->getBoundingBox().containsPoint(pos))
	{
		Sys_Event::getInstance()->dispatchEventWithName(getEventName());
	}
}