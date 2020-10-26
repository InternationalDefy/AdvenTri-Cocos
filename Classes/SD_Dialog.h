#ifndef __SD_DIALOG__
#define __SD_DIALOG__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_Dialog : public SD
{
private:
	ASSIGN_STRING(FileName);
	ASSIGN_DATA(int, Border);
	ASSIGN_DATA(int, Bspace);
	ASSIGN_DATA(int, LSpace);
	ASSIGN_DATA(Vec2, AdjustSize);
private:
	bool init();
public:
	static SD_Dialog* create(const std::string& name);
	static SD_Dialog* create();
};

#endif