#ifndef __SD_ANIMATION_PACK__
#define __SD_ANIMATION_PACK__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_AnimationPack :public SD
{
private:
	ASSIGN_DATA(int, NumberOfAnimations);
	//Vec1 ÊÇkey Vec2 ÊÇAnimationName
	std::map<std::string, std::string> _keysName;
private:
	bool init();
public:
	void setKeyName(const std::string&, const std::string&);
	static SD_AnimationPack* create();
	std::map<std::string, std::string>* getKeyMap()
	{
		return &_keysName;
	}

};


#endif