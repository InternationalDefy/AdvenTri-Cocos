#ifndef __DIALOG_H__
#define __DIALOG_H__

#include "cocos2d.h"

class SD_Dialog;

using namespace cocos2d;

class M_Dialog : public cocos2d::Sprite
{
private:
	//float _adjustSize;
	/**
	�öԻ������չ��С������M_Emoji�ౣ��һ��
	*/
	Vec2 _adjustSize;
	int _border;
	int _Bspace;
	int _Lspace;
	std::string _filename;

public:

	void initWithData(SD_Dialog* dialogdata);

	static M_Dialog* createWithDialogData(SD_Dialog* dialogdata);
	
	void setBorder(int x){ _border = x; }
	/**
	�߽���
	*/
	int getBorder(){ return _border; }

	void setBlockSpace(int x){ _Bspace = x; }
	/**
	���
	*/
	int getBlockSpace(){ return _Bspace; }

	void setLineSpace(int x){ _Lspace = x; }
	/**
	�о�
	*/
	int getLineSpace(){ return _Lspace; }
	/**
	�ı��M_Dialog��AdjustSize��ͬʱ���޸���Scale
	*/
	void setAdjustSize(Vec2 x)
	{
		_adjustSize = x; 
		setScale(x.x/getContentSize().width,x.y/getContentSize().height);
	}
	/**
	�öԻ������չ��С������M_Emoji�ౣ��һ��
	*/
	Vec2 getAdjustSize(){ return _adjustSize; }
	/**
	fileName�Ǵ�����M_Dialog��ʹ�õ��ļ�������clone������ʹ��
	*/
	std::string getFileName()
	{
		return _filename;
	}
};

#endif