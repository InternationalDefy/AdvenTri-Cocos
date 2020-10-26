#ifndef __A_ITEM_STRING_DATA_H__
#define __A_ITEM_STRING_DATA_H__

#include "cocos2d.h"

USING_NS_CC;

class SD_Animate : public Ref
{
private:
	Vector<String*> _frameNames;
	float _delay;
	float _loopDelay;
	int _loop;

public:
	static SD_Animate* create()
	{
		SD_Animate* AitemStringData = new (std::nothrow) SD_Animate();
		if (AitemStringData)
		{
			AitemStringData->autorelease();
			return AitemStringData;
		}
		CC_SAFE_DELETE(AitemStringData);
		return nullptr;
	}
	Animate* getAnimate()
	{
		auto a_temp = Animation::create();
		for (int i = 0; i < _frameNames.size(); ++i)
		{
			a_temp->addSpriteFrameWithFile(_frameNames.at(i)->getCString());
		}
		a_temp->setDelayPerUnit(_delay);
		if (!_loop)
		{
			return Animate::create(a_temp);
		}
		else
		{
			for (int i = 0; i < (_loopDelay / _delay); ++i)
			{
				a_temp->addSpriteFrameWithFile(_frameNames.at(_frameNames.size()-1)->getCString());
			}
			a_temp->setLoops(_loop);
			return Animate::create(a_temp);
		}
	}

	void pushFrameName(String* frameName){ _frameNames.pushBack(frameName); }
	void setDelay(float x){ _delay = x; }
	void setLoop(int x){ _loop = x; }
	void setDelayLoop(float x){ _loopDelay = x; }
};

#endif