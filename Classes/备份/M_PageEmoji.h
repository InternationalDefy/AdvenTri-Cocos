#ifndef __PAGE_OF_PIECE_H__	
#define __PAGE_OF_PIECE_H__

#include "cocos2d.h"

class M_PageEmoji;
class M_Emoji;

using namespace cocos2d;

class M_PageEmoji: public cocos2d::Node
{
private:
	Vector<M_Emoji*> _emojis;

	boolean _pageActivited;

	void activeFinished();

	void handleDelay(Layer* layer, int type);

	void activeUsingFadeIn(Layer* layer);

	void activeUsingForce(Layer* layer);

public:

	static M_PageEmoji* create()
	{
		M_PageEmoji *page = new (std::nothrow) M_PageEmoji();
		if (page)
		{
			page->_pageActivited = false;
			page->autorelease();
			return page;
		}
		CC_SAFE_DELETE(page);
		return nullptr;
	}

	void push(M_Emoji* e);

	void setPosition(Vec2 pos);

	void setEmojiVisible(bool visible);

	/**
	deActive����Ӧ�ô�����ǣ�����Ҫʹ��invisible����ȻҪ�����ڴ����ɾ����Page
	*/
	void deActive();
	/**
	�����Page����RunAction�Ķ�����Layer
	*/
	void pageActive(Layer* layer,int type);

	void resetOrder(int loacalZOrder);

	//getters
	bool isActived()
	{
		return _pageActivited;
	}
};

#endif