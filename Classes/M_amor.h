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
	//���´���Amor�Ĵ����ͳ�ʼ������
private:
	int _defence;
	int _hp;
	AdvenTriEnum::AmorType _type;
	M_Enemy* _owner;
	void initWithData(SD_Amor* a_breed);
public:
	void addToEnemy(M_Enemy* enemy);
	//���´���Amor��ANimation
private:
	M_AnimationPack* _animationPack;
	Animate* _animate;
	bool _animateRunning;
public:
	//void activeAnimate(const std::string& key);
	void deActiveAnimate();
public:
	static M_Amor* create(SD_Amor* a_breed);
	//���²��ִ���ʵ���˺���Amor�ĵ��ú���Ӧ��

	//��Debuffʱ�����Ӧ
public:
	static float handleDebuffDuration(M_Amor* amor, AdvenTriEnum::DamageType T, float F);
private:
	static float handleDurationMagic(AdvenTriEnum::DamageType T);
	static float handleDurationMetal(AdvenTriEnum::DamageType T);
	static float handleDurationWood(AdvenTriEnum::DamageType T);
	//���˺�����ֵ����Ӧ
public:
	static int handleDamageNum(M_Amor* amor, AdvenTriEnum::DamageType T, int D);
private:
	static int handleDamageMagic(AdvenTriEnum::DamageType T);
	static int handleDamageMetal(AdvenTriEnum::DamageType T);
	static int handleDamageWood(AdvenTriEnum::DamageType T);
};
#endif