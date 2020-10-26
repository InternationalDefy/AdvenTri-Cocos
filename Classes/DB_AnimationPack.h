#ifndef __DB_ANIMATION_PACK__
#define __DB_ANIMATION_PACK__

#include "cocos2d.h"

#include "Ref_DataBase.h"

class SD_AnimationPack;

USING_NS_CC;

class DB_AnimationPack: public DB
{
private:
	SD_AnimationPack* tempPack;
		
	std::string tempName;
	std::string tempKey;
	std::string tempAnimateName;

	Map<std::string, SD_AnimationPack*> _animationTable;
	
public:
	
	void getLine(const std::string& data);
	std::string useString(){ return "Table_AnimationPack.csv"; }
	/*
	@param const std::string& _name
	*/
	SD_AnimationPack* getAnimationPackSD(const std::string& name);

	static DB_AnimationPack* create();
	static DB_AnimationPack* getInstance();
};

#endif