#ifndef __PAGE_OF_PIECE_H__	
#define __PAGE_OF_PIECE_H__

#include "cocos2d.h"

class M_PageEmoji;
class M_Emoji;

using namespace cocos2d;

class M_PageEmoji: public cocos2d::Node
{
	//��������
private:
	Vector<M_Emoji*> _emojis;
	bool _pageActivited;
	bool _isActiving;
	int _cEmoji;
	float _cTime;
	//��������
private:
	void activeFinished();
public:
	void resetOrder(int loacalZOrder);
	void setEmojiVisible(bool visible);
	void update(float dt);
	//�����뷴����
public:
	void pageActive();
	/**
	deActive����Ӧ�ô�����ǣ�����Ҫʹ��invisible����ȻҪ�����ڴ����ɾ����Page
	*/
	void deActive();
	//�������ʼ��
public:
	static M_PageEmoji* create()
	{
		M_PageEmoji *page = new (std::nothrow) M_PageEmoji();
		if (page)
		{
			page->_pageActivited = false;
			page->_isActiving = false;
			page->_cEmoji = 0;
			page->_cTime = 0;
			page->autorelease();
			return page;
		}
		CC_SAFE_DELETE(page);
		return nullptr;
	}
	void push(M_Emoji* e);
	//getters
	bool isActived()
	{
		return _pageActivited;
	}
	bool isActiving()
	{
		return _isActiving; 
	}
};

#endif