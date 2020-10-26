#ifndef __LA_EMOJI_LIST_H__	
#define __LA_EMOJI_LIST_H__

#include "cocos2d.h"
#include "Emoji.h"
#include "Dialog.h"

USING_NS_CC;

	/**
* LaEmojiList�����һ�ζԻ�������
*/
class LaEmojiList : public Ref
{
private:
	/**
	_type��ʾ�˵�ǰ�Ի�������ͣ���Dataϵͳ��ʼ��ʱ����
	1����DialogInstant 2����Dialog��Delay 3:��DialogInstant 4����DiaLog��Delay
	*�ڶ������
	_type��ʾ�˵�ǰ�Ի�������ͣ�
	0����delay 1����delay 
	�Ƿ���Dialog�޹ؽ�Ҫ����Ϊ�����ÿ�ͼƬBlank.png����ʾ�޶Ի���ͬʱ�����Ե�����С
	*/
	//int _type;
	/**
	n��ʾ��ǰ��ζԻ�����������Ŀ
	*/
	int n;
	/**
	m��ʾ��Ҫ��ȡ���ݵ���Ŀ������DATA��ʼ��ʱ��Ҫ�õ����ұ�����
	*/
	int m;
	/*
	animated��ʾ�ö����Ƿ���Animation
	�Լ�ӵ��������Animation
	**/
	int _animation;

	Dialog* _thisDialog;

	Vector<Emoji*> _emojis;

	void init(){};

public:

	static LaEmojiList* create()
	{
		LaEmojiList *laEmojiList = new (std::nothrow) LaEmojiList();
		if (laEmojiList)
		{
			laEmojiList->init();
			return laEmojiList;
		}
		CC_SAFE_DELETE(laEmojiList);
		return nullptr;
	}

	//setters & getters
	int getNumberOfEmojis(){ return n; }
	int getNumberOfItems(){ return m; }
	int getAnimationType(){ return _animation; }
	Dialog* getDialog(){ return _thisDialog; }
	Vector<Emoji*>* getEmojis(){ return &_emojis; }
	void setNumberOfEmojis(int x){ n = x; }
	void setNumberOfItems(int x){ m = x; }
	void setDialog(Dialog* dialog){ _thisDialog = dialog; }
	void setAnimation(int x){ _animation = x; }

	void setNothing(int x){ return; }
};
#endif