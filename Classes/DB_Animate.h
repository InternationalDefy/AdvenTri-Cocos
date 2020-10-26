#ifndef __DB_ANIMATE__
#define __DB_ANIMATE__

#include "cocos2d.h"

#include "Ref_DataBase.h"

class M_AnimationPack;
class SD_Animate;

USING_NS_CC;

class DB_Animate: public DB
{
private:
	SD_Animate* tempAnimationData;

	std::string tempName;
	std::string tempKey;

	Map<std::string, SD_Animate*> _animationTable;
	
public:
	
	void getLine(const std::string& data);
	std::string useString(){ return "Table_Animate.csv"; }

	Animate* getAnimate(const std::string& key);
	SD_Animate* getAnimationData(const std::string& key);

	static DB_Animate* create();
	static DB_Animate* getInstance();
};

#endif