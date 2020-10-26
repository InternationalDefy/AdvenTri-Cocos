#ifndef __ANIMATION_PACK_H__
#define __ANIMATION_PACK_H__

#include "cocos2d.h"

USING_NS_CC;

class SD_Animate;

class M_AnimationPack : public Ref
{
private:

	Map<std::string, FiniteTimeAction*> _animationTable;
public:
	static M_AnimationPack* create();
	
	void addAnimation(const std::string & name,FiniteTimeAction* animation);
	/*
	���ص���һ����¡
	*/
	FiniteTimeAction* getAnimation(const std::string & key);

};

#endif