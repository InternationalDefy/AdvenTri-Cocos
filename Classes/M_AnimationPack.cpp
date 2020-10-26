#include "Ref2Animation.h"

using namespace cocos2d;

M_AnimationPack* M_AnimationPack::create()
{
	M_AnimationPack* ret = new (std::nothrow) M_AnimationPack();
	if (ret)
	{
		//内存管理的问题暂不考虑，autorelease和retain何时何者的使用，一会实验得出结论
		//ret->retain();
		//ret->autorelease();
	}
	else
	{
		CC_SAFE_DELETE(ret);
	}
	return ret;
}

void M_AnimationPack::addAnimation(const std::string& name, FiniteTimeAction* animation)
{
	_animationTable.insert(name, animation);
}

FiniteTimeAction* M_AnimationPack::getAnimation(const std::string& key)
{
	if (_animationTable.at(key))
	{
		return _animationTable.at(key)->clone();
	}
	else
	{
		auto k = "Animate in Animation Pack Name " + key + " UNFOUND!";
		log(k.c_str());
	}
}