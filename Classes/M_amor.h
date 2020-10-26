#ifndef __M_AMOR__
#define __M_AMOR__

#include "cocos2d.h"
#include "Ref_Enum.h"

#define AMOR_PLUS_DAMAGE(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (1); \
} \

#define AMOR_PLUS2DAMAGE(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (2); \
} \

#define AMOR_MIUS_DAMAGE(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (-1); \
} \

#define AMOR_MIUS2DAMAGE(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (-2); \
} \

#define AMOR_PLUS_DURATION(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (2.0f); \
} \

#define AMOR_MIUS_DURATION(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (-2.0f); \
} \

#define AMOR_PLUS2DURATION(__DamageType__) \
if (T == __DamageType__) \
{ \
	return (5.0f); \
} \


USING_NS_CC;

class M_Enemy;
class SD_Amor;
class M_AnimationPack;

class M_Amor : public Node
{
	friend class M_Enemy;
	//以下处理Amor的创建和初始化操作
private:
	int _defence;
	int _hp;
	AdvenTriEnum::AmorType _type;
	M_Enemy* _owner;
	void initWithData(SD_Amor* a_breed);
public:
	void addToEnemy(M_Enemy* enemy);
	//以下处理Amor的ANimation
private:
	M_AnimationPack* _animationPack;
	Animate* _animate;
	bool _animateRunning;
public:
	//void activeAnimate(const std::string& key);
	void deActiveAnimate();
public:
	static M_Amor* create(SD_Amor* a_breed);
	//以下部分处理实体伤害对Amor的调用和响应。

	//对Debuff时间的响应
public:
	static float handleDebuffDuration(M_Amor* amor, AdvenTriEnum::DamageType T, float F);
private:
	static float handleDurationMagic(AdvenTriEnum::DamageType T);
	static float handleDurationMetal(AdvenTriEnum::DamageType T);
	static float handleDurationWood(AdvenTriEnum::DamageType T);
	//对伤害修正值的响应
public:
	static int handleDamageNum(M_Amor* amor, AdvenTriEnum::DamageType T, int D);
private:
	static int handleDamageMagic(AdvenTriEnum::DamageType T);
	static int handleDamageMetal(AdvenTriEnum::DamageType T);
	static int handleDamageWood(AdvenTriEnum::DamageType T);
};
#endif