#include "Ref2UIItem.h"

using namespace cocos2d;

bool UI_Item::init()
{
	_responed = FALSE;
	_spriteNum = 0;
	_responseNum = 0;
	_indiActive = FALSE;
	_itemRect = Rect();
	//_opacityTo = 255;
	setCascadeOpacityEnabled(TRUE);
	return TRUE;
}

void UI_Item::responseItem()
{
	for (auto i = 0; i < _spriteNum; ++i)
	{
		responseSprite(i);
	}
}
void UI_Item::responseSprite(int index)
{
	if (index >= _spriteNum)
	{
		log("Out Of Range!");
		return;
	}
	if (!_sprite.at(index))
	{
		log("This Slot Empty!");
		return;
	}
	responseSprite(index, _sprite.at(index));
}
void UI_Item::responseSprite(int index, Sprite* sp)
{
	_responed = TRUE;
	_responseNum = index;
	sp->runAction(_responseBegin.at(index));
	return;
}
void UI_Item::responseEnd()
{
}
void UI_Item::enterItem()
{
	activeEventListeners();
	for (auto i = 0; i < _spriteNum; ++i)
	{
		enterSprite(i);
	}
}
void UI_Item::enterSprite(int index)
{
	if (index >= _spriteNum)
	{
		log("Out Of Range!");
		return;
	}
	if (!_sprite.at(index))
	{
		log("This Slot Empty!");
		return;
	}
	enterSprite(index, _sprite.at(index));
}
void UI_Item::enterSprite(int index, Sprite* sp)
{
	if (_indiActive) sp->runAction(_enterAction.at(index));
	//assign Listener Or Something.
	return;
}
void UI_Item::quitItem()
{
	deactiveEventListeners();
	for (auto i = 0; i < _spriteNum; ++i)
	{
		_sprite.at(i)->runAction(_quitAction.at(i));
	}
}

void UI_Item::pushCallbackParser(M_CallbackParser* cp)
{
	if (!cp)
	{
		log("Cant!");
		return;
	}
	_callbackParser.push_back(cp);
	cp->retain();
	return;
}
void UI_Item::pushDispatchParser(M_DispatchParser* dp)
{
	if (!dp)
	{
		log("Cant!");
		return;
	}
	_dispatchParser.push_back(dp);
	dp->retain();
	return;
}

void UI_Item::removeFromParent()
{
	auto m = _callbackParser.size();
	for (auto i = 0; i < m; ++i)
	{
		Sys_Event::getInstance()->deleteCallbackFunc(_callbackParser.at(i));
	}
	auto n = _dispatchParser.size();
	for (auto i = 0; i < n; ++i)
	{
		Sys_Event::getInstance()->deleteDispatchFunc(_dispatchParser.at(i));
	}
	Node::removeFromParent();
}

void UI_Item::activeEventListeners()
{
	auto n = _dispatchParser.size();
	for (auto i = 0; i < n; ++i)
	{
		_dispatchParser.at(i)->setParentNode(this);
		_activedDispatchParser.push_back(_dispatchParser.at(i));
	}
	auto m = _callbackParser.size();
	for (auto i = 0; i < m; ++i)
	{
		_callbackParser.at(i)->setParentNode(this);
		_callbackParser.at(i)->assignListener();
		_activedCallbackParser.push_back(_callbackParser.at(i));
	}
	return;
}
void UI_Item::deactiveEventListeners()
{
	auto m = _activedCallbackParser.size();
	for (auto i = 0; i < m; ++i)
	{
		_activedCallbackParser.at(i)->removeFromParentAndCleanup(false);
		_activedCallbackParser.at(i)->retain();
	}
	auto n = _activedDispatchParser.size();
	for (auto i = 0; i < n; ++i)
	{
		_activedCallbackParser.at(i)->removeFromParentAndCleanup(false);
		_activedDispatchParser.at(i)->retain();
	}
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(this, true);
	return;
}
//获取item的所有sprite组合成的boundingbox，在UIlayer坐标系中。
Rect UI_Item::getSpriteBoundingBoxAtUILayer()
{
	//auto k = this->getBoundingBox();
	auto k = Rect();
	k.setRect(
		_itemRect.origin.x+getPositionX()+getParent()->getPositionX(),
		_itemRect.origin.y+getPositionY()+getParent()->getPositionY(),
		_itemRect.size.width,
		_itemRect.size.height);
	return k;
}