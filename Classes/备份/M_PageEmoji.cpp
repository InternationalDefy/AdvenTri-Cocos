#include "Ref2LaEmoji.h"

USING_NS_CC;

void M_PageEmoji::push(M_Emoji* e)
{
	 _emojis.pushBack(e); 
	 addChild(e); 
}
/*
void M_PageEmoji::addToScene(Layer* layer,int zOrder)
{
	for (int i = 0; i < _emojis.size(); ++i)
	{
		layer->addChild(_emojis.at(i), zOrder + 1);
	}
}
*/
void M_PageEmoji::setPosition(Vec2 pos)
{
	for (int i = 0; i < _emojis.size(); ++i)
	{
		_emojis.at(i)->setPosition(Vec2(
			_emojis.at(i)->getPositionX()+pos.x,
			_emojis.at(i)->getPositionY()+pos.y));
	}
}

void M_PageEmoji::setEmojiVisible(bool visible)
{
	for (int i = 0; i < _emojis.size(); ++i)
	{
		_emojis.at(i)->setVisible(visible);
	}
}

void M_PageEmoji::handleDelay(Layer* layer,int type)
{
	switch (type)
	{
	case 0:
		activeUsingForce(layer);
		break;
	case 1:
		activeUsingFadeIn(layer);
		break;
	default:
		break;
	}
}

void M_PageEmoji::pageActive(Layer* layer,int type)
{
	handleDelay(layer,type);
}

void M_PageEmoji::activeUsingFadeIn(Layer* layer)
{
	float floatTemp = 0.0f;
	for (int i = 0; i < _emojis.size(); ++i)
	{
		if (i != _emojis.size() - 1)
		{
			floatTemp += _emojis.at(i)->getDelayTime();
			CallFunc* callFunc = CallFunc::create(std::bind(&M_Emoji::fadeIn, _emojis.at(i), _emojis.at(i)->getDelayTime()));
			layer->runAction(Sequence::create(DelayTime::create(floatTemp - _emojis.at(i)->getDelayTime()), callFunc, NULL));
		}
		else
		{
			floatTemp += _emojis.at(i)->getDelayTime();
			CallFunc* callFunc = CallFunc::create(std::bind(&M_Emoji::fadeIn, _emojis.at(i), _emojis.at(i)->getDelayTime()));
			CallFunc* callFunc2 = CallFunc::create(std::bind(&M_PageEmoji::activeFinished, this));
			layer->runAction(Sequence::create(DelayTime::create(floatTemp - _emojis.at(i)->getDelayTime()), callFunc, callFunc2, NULL));
		}
	}
}

void M_PageEmoji::activeUsingForce(Layer* layer)
{
	float floatTemp = 0.0f;
	for (int i = 0; i < _emojis.size(); ++i)
	{
		if (i != _emojis.size() - 1)
		{
			floatTemp += _emojis.at(i)->getDelayTime();
			CallFunc* callFunc = CallFunc::create(std::bind(&M_Emoji::setVisible, _emojis.at(i), TRUE));
			layer->runAction(Sequence::create(DelayTime::create(floatTemp), callFunc, NULL));
		}
		else
		{
			floatTemp += _emojis.at(i)->getDelayTime();
			CallFunc* callFunc = CallFunc::create(std::bind(&M_Emoji::setVisible, _emojis.at(i), TRUE));
			CallFunc* callFunc2 = CallFunc::create(std::bind(&M_PageEmoji::activeFinished, this));
			layer->runAction(Sequence::create(DelayTime::create(floatTemp), callFunc, callFunc2, NULL));
		}
	}
}

void M_PageEmoji::activeFinished()
{
	_pageActivited = true;
}

void M_PageEmoji::deActive()
{
	setEmojiVisible(false);
}

void M_PageEmoji::resetOrder(int localZOrder)
{
	for (int i = 0; i < _emojis.size(); ++i)
	{
		_emojis.at(i)->setGlobalZOrder(localZOrder);
	}
}