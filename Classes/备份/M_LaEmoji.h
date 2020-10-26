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
	pages��ʾ����ĳһҳ��ȫ�����ݡ�
	���ڶԻ����ܺܶ���Ի����С�̶������Ҫ��ҳ��
	*/
	Vector<M_PageEmoji*> _pages;

	Vector<M_Emoji*> _tempEmojis;

	int _animationType;

	Layer* _parentLayer;
	/**
	��ǰ������ҳ�����ڿ����Ƿ�����һҳ
	*/
	int _activitedPage;
	/**
	���ٸ�PieceOfEmojiʱ���õķ�����Ŀǰ��δʵ�֣��в�����ڴ�������ʵ����ʽ
	*/
	void destroy();
	/**
	���������ʱ����������delay��ᴥ��0�������в�����Ƿ��ް���
	��init��󱻵���
	*/
	void handleDelay();
	/**
	�˺�����Ҫ��������ҳ�¼���Ҳ�п��ܱ����ڸ���Ĺ������
	*/
	void onMouseDown();
	/**
	���¼��������г�ʼ����Ŀǰֻ�ܹ�ʵ�ְ�����ҳ����init������󱻵���
	*/
	void initEventDispatcher();
	/**
	����һҳ��������һҳ�������¼�����ʱ���ã�������ʾ��һҳ
	*/
	void activePage(int deactivedPage);

	virtual void init(SD_LaEmoji* laEmojiList,Layer* layer);

public:
	
	void addToScene(int zOrder);

	void setPosition(Vec2 pos);

	static M_LaEmoji* create(SD_LaEmoji* laEmojiList,Layer* layer);

};

#endif