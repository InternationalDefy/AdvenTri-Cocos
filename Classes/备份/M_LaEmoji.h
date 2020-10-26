#ifndef __PIECE_OF_LAEMOJI_H__
#define __PIECE_OF_LAEMOJI_H__

#include "cocos2d.h"

class M_PageEmoji;
class SD_LaEmoji;
class M_Dialog;

using namespace cocos2d;

class M_LaEmoji : public cocos2d::Node
{
private:
	
	M_Dialog* _thisDialog;
	/**
	pages表示的是某一页的全部内容。
	由于对话可能很多而对话框大小固定，因此要分页。
	*/
	Vector<M_PageEmoji*> _pages;

	Vector<M_Emoji*> _tempEmojis;

	int _animationType;

	Layer* _parentLayer;
	/**
	当前被激活页，用于控制是否开启下一页
	*/
	int _activitedPage;
	/**
	销毁该PieceOfEmoji时调用的方法，目前尚未实现，切不清楚内存管理具体实现形式
	*/
	void destroy();
	/**
	对其进行延时操作处理，无delay则会触发0动作（尚不清楚是否无碍）
	在init最后被调用
	*/
	void handleDelay();
	/**
	此函数主要处理按键翻页事件，也有可能被用于更多的功能添加
	*/
	void onMouseDown();
	/**
	对事件监听进行初始化，目前只能够实现按键翻页，在init函数最后被调用
	*/
	void initEventDispatcher();
	/**
	激活一页动作，在一页被触发事件激活时调用，用于显示下一页
	*/
	void activePage(int deactivedPage);

	virtual void init(SD_LaEmoji* laEmojiList,Layer* layer);

public:
	
	void addToScene(int zOrder);

	void setPosition(Vec2 pos);

	static M_LaEmoji* create(SD_LaEmoji* laEmojiList,Layer* layer);

};

#endif