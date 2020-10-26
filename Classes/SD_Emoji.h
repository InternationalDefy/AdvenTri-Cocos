#ifndef __SD_EMOJI__
#define __SD_EMOJI__

#include "Ref_DataBase.h"
#include "Ref_Enum.h"

using namespace cocos2d;

class SD_Emoji : public SD
{
private:
	ASSIGN_STRING(FileName);
	ASSIGN_DATA(float, TimeDelay);
	ASSIGN_DATA(Vec2, OriginalSize);
	ASSIGN_DATA(float, AdjustSize);
	ASSIGN_STRING(EnterActionType);
	Vector<String*> EnterActionParams;
private:
	bool init();
public:
	void pushEnterActionParam(const std::string& param)
	{
		EnterActionParams.pushBack(String::create(param));
	}
	Vector<String*>* getEnterActionParam()
	{
		return &EnterActionParams; 
	}
	static SD_Emoji* create(const std::string& name);
	static SD_Emoji* create();
};

#endif