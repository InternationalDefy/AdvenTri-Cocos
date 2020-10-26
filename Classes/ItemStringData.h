#ifndef __ITEM_STRING_DATA_H__
#define __ITEM_STRING_DATA_H__

#include "cocos2d.h"

USING_NS_CC;

class ItemStringData : public Ref
{
private:
	Vector<String*> _strings;

public:
	/**
	ItemStringData ��һ�в�ͬ��Item
	ÿ��Item��һ��string
	���Ա����ֲ�ͬ��StringData�������ʹ����ʵ�����д洢����
	*/
	static ItemStringData* create()
	{

		ItemStringData* itemStringData = new (std::nothrow) ItemStringData();
		if (itemStringData)
		{
			itemStringData->autorelease();
			return itemStringData;
		}
		CC_SAFE_DELETE(itemStringData);
		return nullptr;
	}
	Vector<String*>* getStrings(){ return &_strings; }
	void pushIn(String* x){ _strings.pushBack(x); }
};

#endif