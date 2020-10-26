#include "Ref2LaEmoji.h"

USING_NS_CC;

void M_PageEmoji::deActive()
{
	setEmojiVisible(false);
}
void M_PageEmoji::pageActive()
{
	_isActiving = true;
	_emojis.at(_cEmoji)->enterToDialog();
	_cEmoji += 1;
}
void M_PageEmoji::activeFinished()
{
	_pageActivited = true;
	_isActiving = false;
}

void M_PageEmoji::resetOrder(int localZOrder)
{
	for (int i = 0; i < _emojis.size(); ++i)
	{
		_emojis.at(i)->setGlobalZOrder(localZOrder);
	}
}
void M_PageEmoji::push(M_Emoji* e)
{
	_emojis.pushBack(e);
	addChild(e, 3);
}
void M_PageEmoji::setEmojiVisible(bool visible)
{
	for (int i = 0; i < _emojis.size(); ++i)
	{
		_emojis.at(i)->setVisible(visible);
	}
}
void M_PageEmoji::update(float dt)
{
	if (_isActiving)
	{
		_cTime += dt;
		if (_cTime >= _emojis.at(_cEmoji - 1)->getDelayTime())
		{
			_emojis.at(_cEmoji)->enterToDialog();
			_cEmoji += 1;
			_cTime = 0.0f;
			if (_cEmoji == _emojis.size())
			{
				_cEmoji = 0;
				activeFinished();
				return;
			}
			return;
		}
	}
	return;
}