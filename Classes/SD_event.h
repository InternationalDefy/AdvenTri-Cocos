#ifndef __SD_EVENTS__
#define __SD_EVENTS__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_Event : public SD
{
private :
	ASSIGN_STRING(ParamType);
	ASSIGN_STRING(Param);
private:
	bool init();
public :
	//CREATE_FUNC(SD_PlayerController);
	static SD_Event* create();

	//Ctrl_Player* createPctrlFromSD();
};

#endif