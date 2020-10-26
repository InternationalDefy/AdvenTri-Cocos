#ifndef __EMOJI_H__	
#define __EMOJI_H__

#include "cocos2d.h"
using namespace cocos2d;

class SD_Emoji;

class M_Emoji	: public cocos2d::Sprite
{
private:
	/**
	_adjustSize�Ƕ�Size������������ʾ���ΪAdjust��
	*/
	float _adjustSize;
	/**
	�ڸñ������֮ǰ�õ�ʱ��
	*/
	float _delayTime;
	/**
	_size�Ǹñ������ʵ�ߴ�
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
	�ò����ж�fileName��Sprite�ĳ�ʼ��
	*/
	void setSpriteTexture(const std::string& filename)
	{ 
		initWithFile(filename); 
		_fileName = filename;
	}
	void setDelayTime(float x)	{ _delayTime = x; }
	/**
	�ڸñ������֮ǰ�õ�ʱ��
	*/
	float getDelayTime(){ return _delayTime; }
	/**
	_adjustSize�Ƕ�Size������������ʾ���ΪAdjust��
	�ù���ֱ�Ӹı��M_Emoji��ʵ��Size
	*/
	void setAdjustSize(float x)
	{
		_adjustSize = x; 
		setScale(_adjustSize);
		_size = Vec2(_adjustSize*getContentSize().width,
			_adjustSize*getContentSize().height);
	}
	/**
	_adjustSize�Ƕ�Size������������ʾ���ΪAdjust��
	*/
	float getAdjustSize()
	{
		return _adjustSize;
	}
	/**
	size���ص�����ʵ�ĳߴ磬��Adjust��չ֮��
	*/
	Vec2 getSize(){ return _size; }
	std::string getFileName()
	{
		return _fileName;
	}
};

#endif