#ifndef __LA_EMOJI_LIST_H__	
#define __LA_EMOJI_LIST_H__

#include "cocos2d.h"
#include "Emoji.h"
#include "Dialog.h"

USING_NS_CC;

	/**
* LaEmojiList类就是一段对话的数据
*/
class LaEmojiList : public Ref
{
private:
	/**
	_type表示了当前对话框的类型，在Data系统初始化时创建
	1：无DialogInstant 2：无Dialog有Delay 3:有DialogInstant 4：有DiaLog有Delay
	*第二版设计
	_type表示了当前对话框的类型，
	0：无delay 1：有delay 
	是否有Dialog无关紧要，因为可以用空图片Blank.png来表示无对话框，同时还可以调整大小
	*/
	//int _type;
	/**
	n表示当前这段对话里表情的总数目
	*/
	int n;
	/**
	m表示需要读取数据的项目数，在DATA初始化时需要用到并且被访问
	*/
	int m;
	/*
	animated表示该动作是否有Animation
	以及拥有怎样的Animation
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