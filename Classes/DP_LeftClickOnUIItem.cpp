#include "Ref2EventSystem.h"
#include "Ref_UIItem.h"
#include "SD_dispatcher.h"

using namespace cocos2d;

CREATE_DISPATCHPARSER(DP_LeftClickOnUIItem);

void DP_LeftClickOnUIItem::initWithStringData(SD_Dispatcher* stringData)
{
	return;
}

void DP_LeftClickOnUIItem::setParentNode(Node* parent)
{
	M_DispatchParser::setParentNode(parent);
	auto lis = EventListenerMouse::create();
	lis->onMouseDown = CC_CALLBACK_1(DP_LeftClickOnUIItem::onMouseDownCallback, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(lis, parent);
}

void DP_LeftClickOnUIItem::onMouseDownCallback(Event* event)
{
	if (isLocked())
		return;
	auto eventMouse = (EventMouse*)event;
	auto pos = Vec2(eventMouse->getCursorX(),
		eventMouse->getCursorY());
	auto item = (UI_Item*)getParent();
	int k = item->getSprites()->size();
	for (int i = 0; i < k; ++i)
	{
		if (item->getSpriteBoundingBoxAtUILayer().containsPoint(pos))
		{
			Sys_Event::getInstance()->dispatchEventWithName(getEventName());
			updateLimit();
			return;
		}
	}
	return;
}