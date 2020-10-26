#ifndef __SD_ITEMSTATE__
#define __SD_ITEMSTATE__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_ItemState : public SD
{
private:
	ASSIGN_STRING(ItemName);
	ASSIGN_STRING(UISetName);
	ASSIGN_STRING(ItemEntity);
	ASSIGN_STRING(UsingAnimateName);
	ASSIGN_DATA(float, UsingTime);
	ASSIGN_STRING(DropFuncName);
	ASSIGN_STRING(PickUpAnimate);
	ASSIGN_DATA(int, NumberOfDropFuncParams);
	ASSIGN_DATA(std::vector<std::string>, DropFuncParams);
	ASSIGN_DATA(int, NumberOfUseFunc);
	ASSIGN_ITEMS();

private:
	bool init();
public:
	//CREATE_FUNC(SD_PlayerController);
	static SD_ItemState* create();

	void pushDropFuncParam(const std::string& str)
	{
		_DropFuncParams.push_back(str);
	}
	/*
	取用UseFunc的数据记录，实质是SD_Item
	注意lines.at(id)->getString()->at(0)为Use Func Type
	*/
	SD_Item* getUseFunc(int id)
	{
		return _lines.at(id);
	}

	//Ctrl_Player* createPctrlFromSD();
};

#endif