#ifndef __ENEMY_H__	
#define __ENEMY_H__

#include "cocos2d.h"
#include "Ref_Enum.h"
#include "Entity.h"

class M_Amor;
class M_weapon;
class Ctrl_Base;
class M_AnimationPack;
class M_EnemyState;

class SD_Eskill;
class M_Eskill;

class Entity;

using namespace cocos2d;

class M_Enemy : public Entity
{
	friend class M_Amor;
	friend class M_weapon;
	//����ʵ��ĺ�����
public:
	static M_Enemy* create(const std::string& filename);

	//���²���Ϊʵ��Ĺ���ͳ�ʼ��������
private:
	inline void initData();
	//inline void update(float delta);
	M_Amor* _amor;
	M_weapon* _weapon;
	//M_AnimationPack* _animationPack;
	int _hp;
	int _Maxhp;
public:
	void addAmor(M_Amor* amor);
	void addWeapon(M_weapon* weapon);
	void addAnimationPack(M_AnimationPack* animationPack);

	//���²��ִ���ʵ��Ķ���ִ�С�
private:
	bool _animateRunning;
public:
	//void activeAnimate(const std::string& key);
	void animationEndCallback();

	//���²�������ʵ����ܵ��˺��Լ�Debuff������
private:
	std::map<AdvenTriEnum::Debuff, bool> _onDebuff;
	std::map<AdvenTriEnum::Debuff, float> _debuffTime;
	std::map<AdvenTriEnum::Debuff, float> _debuffLimit;
	std::map<AdvenTriEnum::Debuff, float> _debuffCount;
	void handleDebuffEnter(AdvenTriEnum::Debuff debuff);
	void handleDebuffEffect(AdvenTriEnum::Debuff debuff);
	void handleDebuffOut(AdvenTriEnum::Debuff debuff);
	void handleDebuffOut(AdvenTriEnum::Debuff debuff1, AdvenTriEnum::Debuff debuff2);
	Sprite* _debuffNode;
	float _onDebuffLimit;
	float _hurtingTime;
	bool _hurting;
private:
	//�ⲿset���ʼ����ʱ������ΪĬ��ֵ����hurt����֮ǰ�����ã�ʹ�ú����û�Ĭ��ֵ��
	AdvenTriEnum::DamageType _onHurtType;
	float _onHurtDamage;
public:
	void doHurt();
public:
	void setHurtType(AdvenTriEnum::DamageType x)
	{
		_onHurtType = x;
		return;
	}
	AdvenTriEnum::DamageType getHurtType()
	{
		return _onHurtType;
	}
	void setHurtDamage(float x)
	{
		_onHurtDamage = x;
		return;
	}
	float getHurtDamage()
	{
		return _onHurtDamage;
	}
	void setDebuffLimit(float x)
	{
		_onDebuffLimit = x;
		return;
	}
	bool isHurting()
	{
		return _hurting;
	}
	
	//���²������֡�
private:
	void updateDebuffTime(AdvenTriEnum::Debuff debuff, float dt);
	void updateHurtingTime(float dt);
	void updateLogic(float dt);
public:
	void update(float dt);

	//���²��ִ����ܲ���
	//���´����ܵ���ȴ�͹���
private:
	Map<std::string, M_Eskill*> _skills;
	std::map<std::string, bool> _skillReady;
	std::map<std::string, float> _skillCooldown;
	std::map<std::string, float> _skillLimit;
	void updateSkillCooldown(const std::string& name,float dt);
public:
	void addSkill(const std::string& position, SD_Eskill* SD);
public:
	//Ŀ��Vec2 ʹ�ü���ʱ����
	Vec2 getDashVec2();
	//����Ϊֱ��ʹ�����������ͼ���
	void dash(){ activeSkill("Dash"); }
	void dashAttack(){ activeSkill("DashAttack"); }
	void parry(){ activeSkill("Parry"); }
	void attack(){ activeSkill("SimpleAttack"); }
	//���ڿ��ǣ��Ƿ���Ҫ��Blink����Ϊĳһλ�ã�Ҳ����Ҫ��Controller��Vec2 _target���
	void blink(){ activeSkill("Blink"); }
	void activeSkill(const std::string& key);
	//�����Ƕ�State��״̬����
public:
	void handleAction(AdvenTriEnum::EnemyAction action);
private:
	M_EnemyState* _state;
public:
	void setState(M_EnemyState* state);


	inline void destroy();
	//getters&setters

};

#endif