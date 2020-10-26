#ifndef __C_ITEM_STRING_DATA_H__
#define __C_ITEM_STRING_DATA_H__

#include "cocos2d.h"

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_Ctrl : public SD
{
private:
	virtual bool init()
	{
		return true;
	}
	ASSIGN_ITEMS();
	ASSIGN_DATA(float, Delta);
	ASSIGN_DATA(int, NumberOfLines);
	ASSIGN_STRING(Type);
public:
	CREATE_FUNC(SD_Ctrl);
};

#endif