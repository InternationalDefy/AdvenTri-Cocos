#ifndef __DB_ANIMATION__
#define __DB_ANIMATION__

#include "Ref_DataBase.h"

class SD_Animation;

using namespace cocos2d;

class DB_Animation :public DB
{
private:
	SD_Animation* tempSD;
	std::string tempName;
	Map<std::string, SD_Animation*> _table;
public:
	std::string useString(){ return "Table_Animation.csv";}
	void getLine(const std::string& data);
	
	static DB_Animation* create();
	static DB_Animation* getInstance();

	SD_Animation* getAnimationSD(const std::string& name);

};
#endif