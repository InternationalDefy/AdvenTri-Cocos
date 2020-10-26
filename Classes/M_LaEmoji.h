#ifndef __PIECE_OF_LAEMOJI_H__
#define __PIECE_OF_LAEMOJI_H__

#include "cocos2d.h"

class M_PageEmoji;
class M_Dialog;
class Sys_LaEmoji;
class SD_LaEmoji;

using namespace cocos2d;
/*
M_LaEmoji�಻�����¼����ƣ�������UI����ʵ�֡�
*/
class M_LaEmoji : public cocos2d::Node
{
	friend class Sys_LaEmoji;
private:
	//��������
	M_Dialog* _thisDialog;
	Vector<M_PageEmoji*> _pages;
	Vector<M_Emoji*> _tempEmojis;
	FiniteTimeAction* _enterAction;
	/**
	��ǰ������ҳ�����ڿ����Ƿ�����һҳ
	*/
	int _currentPage;
	bool _laEmojiActived;
	//��������ʼ��
private:
	//void init(SD_LaEmoji* laEmojiList);
public:
	//static M_LaEmoji* create(SD_LaEmoji* laEmojiList);
	static M_LaEmoji* create();
	bool init();
	//void addToScene(Layer* layer, int zOrder);
private:
	//�߼�����
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
	����һҳ��������һҳ�������¼�����ʱ���ã�������ʾ��һҳ
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
	//ʱ�����
	/**
	�˺�����Ҫ��������ҳ�¼���Ҳ�п��ܱ����ڸ���Ĺ������
	*/
	//void onMouseDown();
	/**
	���¼��������г�ʼ����Ŀǰֻ�ܹ�ʵ�ְ�����ҳ����init������󱻵���
	*/
	//void initEventDispatcher();
};

#endif