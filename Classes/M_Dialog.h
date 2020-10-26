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
	该对话框的拓展大小，需与M_Emoji类保持一致
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
	边界宽度
	*/
	int getBorder(){ return _border; }

	void setBlockSpace(int x){ _Bspace = x; }
	/**
	格距
	*/
	int getBlockSpace(){ return _Bspace; }

	void setLineSpace(int x){ _Lspace = x; }
	/**
	行距
	*/
	int getLineSpace(){ return _Lspace; }
	/**
	改变该M_Dialog的AdjustSize，同时会修改其Scale
	*/
	void setAdjustSize(Vec2 x)
	{
		_adjustSize = x; 
		setScale(x.x/getContentSize().width,x.y/getContentSize().height);
	}
	/**
	该对话框的拓展大小，需与M_Emoji类保持一致
	*/
	Vec2 getAdjustSize(){ return _adjustSize; }
	/**
	fileName是创建该M_Dialog所使用的文件名，在clone方法中使用
	*/
	std::string getFileName()
	{
		return _filename;
	}
};

#endif