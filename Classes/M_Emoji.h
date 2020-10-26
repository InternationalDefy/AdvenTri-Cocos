#ifndef __EMOJI_H__	
#define __EMOJI_H__

#include "cocos2d.h"
using namespace cocos2d;

class SD_Emoji;

class M_Emoji	: public cocos2d::Sprite
{
private:
	/**
	_adjustSize是对Size的扩充数，表示其变为Adjust倍
	*/
	float _adjustSize;
	/**
	在该表情出现之前用的时间
	*/
	float _delayTime;
	/**
	_size是该表情的真实尺寸
	*/
	Vec2 _size;
	std::string _fileName;
public:
	static M_Emoji* createWithEmojiData(SD_Emoji* emojidata);
	virtual void initWithData(SD_Emoji* emojidata);
public:
	void enterToDialog();
private:
	FiniteTimeAction* _enterAction;
public:
	void setEnterAction(FiniteTimeAction* action);
public:
	//setters & getters
	/**
	该操作有对fileName的Sprite的初始化
	*/
	void setSpriteTexture(const std::string& filename)
	{ 
		initWithFile(filename); 
		_fileName = filename;
	}
	void setDelayTime(float x)	{ _delayTime = x; }
	/**
	在该表情出现之前用的时间
	*/
	float getDelayTime(){ return _delayTime; }
	/**
	_adjustSize是对Size的扩充数，表示其变为Adjust倍
	该过程直接改变该M_Emoji的实际Size
	*/
	void setAdjustSize(float x)
	{
		_adjustSize = x; 
		setScale(_adjustSize);
		_size = Vec2(_adjustSize*getContentSize().width,
			_adjustSize*getContentSize().height);
	}
	/**
	_adjustSize是对Size的扩充数，表示其变为Adjust倍
	*/
	float getAdjustSize()
	{
		return _adjustSize;
	}
	/**
	size返回的是真实的尺寸，在Adjust扩展之后
	*/
	Vec2 getSize(){ return _size; }
	std::string getFileName()
	{
		return _fileName;
	}
};

#endif