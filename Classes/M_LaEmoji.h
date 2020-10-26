#ifndef __PIECE_OF_LAEMOJI_H__
#define __PIECE_OF_LAEMOJI_H__

#include "cocos2d.h"

class M_PageEmoji;
class M_Dialog;
class Sys_LaEmoji;
class SD_LaEmoji;

using namespace cocos2d;
/*
M_LaEmoji类不管理事件机制，它们由UI部分实现。
*/
class M_LaEmoji : public cocos2d::Node
{
	friend class Sys_LaEmoji;
private:
	//自身属性
	M_Dialog* _thisDialog;
	Vector<M_PageEmoji*> _pages;
	Vector<M_Emoji*> _tempEmojis;
	FiniteTimeAction* _enterAction;
	/**
	当前被激活页，用于控制是否开启下一页
	*/
	int _currentPage;
	bool _laEmojiActived;
	//创建及初始化
private:
	//void init(SD_LaEmoji* laEmojiList);
public:
	//static M_LaEmoji* create(SD_LaEmoji* laEmojiList);
	static M_LaEmoji* create();
	bool init();
	//void addToScene(Layer* layer, int zOrder);
private:
	//逻辑操作
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
	激活一页动作，在一页被触发事件激活时调用，用于显示下一页
	*/
	//void activePage(int deactivedPage); 
	//void activeLaEmoji();
public:
	void nextPage();
	void lastPage();
	void enter();
	void exit();
	bool isPageActiveFinished();
	bool isActived(){ return _laEmojiActived; }
	void onEnter();
	bool isLaEmojiActived()
	{
		return _laEmojiActived;
	}
	void update(float dt);
private:
	//时间监听
	/**
	此函数主要处理按键翻页事件，也有可能被用于更多的功能添加
	*/
	//void onMouseDown();
	/**
	对事件监听进行初始化，目前只能够实现按键翻页，在init函数最后被调用
	*/
	//void initEventDispatcher();
};

#endif