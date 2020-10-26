#ifndef __SD_DISPATCHER__
#define __SD_DISPATCHER__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_Dispatcher : public SD
{
private :
	ASSIGN_STRING(UpsendingEventName);
	ASSIGN_STRING(ListeningFuncType);
	ASSIGN_DATA(int, LimitTimes);
	ASSIGN_DATA(float, CooldownTime);
	ASSIGN_DATA(int, NumberOfParamas);
	ASSIGN_DATA(std::vector<std::string>, Params);
private:
	bool init();
public :
	//CREATE_FUNC(SD_PlayerController);
	static SD_Dispatcher* create();

	void pushString(const std::string& str)
	{
		_Params.push_back(str);
	}

	//Ctrl_Player* createPctrlFromSD();
};

#endif