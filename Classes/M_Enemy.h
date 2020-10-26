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
	//创建实体的函数。
public:
	static M_Enemy* create(const std::string& filename);

	//以下部分为实体的构造和初始化操作。
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

	//以下部分处理实体的动画执行。
private:
	bool _animateRunning;
public:
	//void activeAnimate(const std::string& key);
	void animationEndCallback();

	//以下操作处理实体的受到伤害以及Debuff操作。
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
	//外部set项，初始化的时候设置为默认值，在hurt操作之前被设置，使用后设置回默认值。
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
	
	//更新操作部分。
private:
	void updateDebuffTime(AdvenTriEnum::Debuff debuff, float dt);
	void updateHurtingTime(float dt);
	void updateLogic(float dt);
public:
	void update(float dt);

	//以下部分处理技能部分
	//以下处理技能的冷却和管理
private:
	Map<std::string, M_Eskill*> _skills;
	std::map<std::string, bool> _skillReady;
	std::map<std::string, float> _skillCooldown;
	std::map<std::string, float> _skillLimit;
	void updateSkillCooldown(const std::string& name,float dt);
public:
	void addSkill(const std::string& position, SD_Eskill* SD);
public:
	//目标Vec2 使用技能时访问
	Vec2 getDashVec2();
	//以下为直接使用立即触发型技能
	void dash(){ activeSkill("Dash"); }
	void dashAttack(){ activeSkill("DashAttack"); }
	void parry(){ activeSkill("Parry"); }
	void attack(){ activeSkill("SimpleAttack"); }
	//还在考虑，是否需要把Blink设置为某一位置，也许需要和Controller的Vec2 _target结合
	void blink(){ activeSkill("Blink"); }
	void activeSkill(const std::string& key);
	//以下是对State的状态处理
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