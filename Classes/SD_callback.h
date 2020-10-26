#ifndef __SD_CALLBACK__
#define __SD_CALLBACK__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_Callback : public SD
{
private:
	ASSIGN_DATA(int, FixedProximity);
	ASSIGN_DATA(float, CoolDownTime);
	ASSIGN_DATA(int, LimitedTimes);
	ASSIGN_STRING(UprecivingEventName);
	ASSIGN_STRING(CallbackFuncType);
	ASSIGN_DATA(int, NumberOfParams);
	ASSIGN_DATA(bool, Swallow);
	ASSIGN_DATA(std::vector<std::string>, Params);
private:
	bool init();
public:
	//CREATE_FUNC(SD_PlayerController);
	static SD_Callback* create();
	void pushString(const std::string& str)
	{
		_Params.push_back(str);
	}

	//Ctrl_Player* createPctrlFromSD();
};

#endif