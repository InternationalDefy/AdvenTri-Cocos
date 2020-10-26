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
	ItemStringData 是一行不同的Item
	每个Item是一个string
	可以被各种不同的StringData当作组件使用以实现逐行存储数据
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