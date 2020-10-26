#ifndef __SD_ITEMENTITY__
#define __SD_ITEMENTITY__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_ItemEntity : public SD
{
private:
	ASSIGN_STRING(ItemName);
	ASSIGN_STRING(TextureName);
	ASSIGN_STRING(ItemState);
	ASSIGN_STRING(DropAnimateName);
	ASSIGN_DATA(float, DropDelay);
	ASSIGN_DATA(float, TimeExist);
	ASSIGN_STRING(PhysicsBodyName);
	ASSIGN_STRING(DropController);
	ASSIGN_STRING(FlyingController);
	ASSIGN_STRING(FlyingEndFuncName);
	ASSIGN_DATA(int, NumberOfFlyEndFuncParams);
	ASSIGN_DATA(std::vector<std::string>, FlyEndFuncParams);

private:
	bool init();
public:
	static SD_ItemEntity* create();

	void pushFlyEndFuncParam(const std::string& str)
	{
		_FlyEndFuncParams.push_back(str);
	}
};

#endif