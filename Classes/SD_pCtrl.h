#ifndef __SD_PLAYER_CONTROLLER__
#define __SD_PLAYER_CONTROLLER__

#include "Ref_DataBase.h"

class Ctrl_Player;

using namespace cocos2d;

class SD_pCtrl : public SD
{
private :
	ASSIGN_DATA(float,Force);
	ASSIGN_DATA(float,Vangular);
private:
	bool init();
public :
	//CREATE_FUNC(SD_PlayerController);
	static SD_pCtrl* create();
	Ctrl_Player* createPctrlFromSD();
};

#endif