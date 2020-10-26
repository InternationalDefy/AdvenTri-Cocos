#ifndef __PLAYER_H__	
#define __PLAYER_H__

#include "cocos2d.h"
#include "Ref_Enum.h"
#include "Entity.h"

class Ctrl_Base;
class M_pSkill;
class M_PlayerState;

using namespace cocos2d;

class Entity;

class M_Player : public Entity
{
friend class M_PlayerState;

private:
	inline void initData();
	//updateSkillCoolDown应该在State里执行？
	//void updateSkillCoolDown();
	int _hp;
	int _Maxhp;
private:
	void logicUpdate(float dt);
public:
	Sprite* _parryNode;
	//以下处理伤害Debuff的状态
private:
	std::map<AdvenTriEnum::Debuff, bool> _onDebuff;
	std::map<AdvenTriEnum::Debuff, float> _debuffTime;
	std::map<AdvenTriEnum::Debuff, float> _debuffLimit;
	std::map<AdvenTriEnum::Debuff, float> _debuffCount;
	void updateDebuffTime(AdvenTriEnum::Debuff debuff, float dt);
	void handleDebuffEnter(AdvenTriEnum::Debuff debuff);
	void handleDebuffEffect(AdvenTriEnum::Debuff debuff);
	void handleDebuffOut(AdvenTriEnum::Debuff debuff);
	void handleDebuffOut(AdvenTriEnum::Debuff debuff1, AdvenTriEnum::Debuff debuff2);
	Sprite* _debuffNode;
	float _onDebuffLimit;
private:
	M_PlayerState* _state;
public:
	void setState(M_PlayerState* state);
private:
	//外部set项，初始化的时候设置为默认值，在hurt操作之前被设置，使用后设置回默认值。
	AdvenTriEnum::DamageType _onHurtType;
	float _onHurtDamage;

	//以下处理hurt和skill和parry的冷却计时器。
	void updateHurtingTime(float dt);
	
	float _hurtingTime;
	bool _hurting;

	Map<std::string, M_pSkill*> _skills;
	//?应该不需要 std::map<std::string, float> _skillLimit;
	std::map<std::string, float> _skillCoolDown;
	std::map<std::string, bool> _skillReady;
public:
	bool isSkillReady(const std::string& posName)
	{
		int i = 1;
		return _skillReady.at(posName);
	}
	//冷却时间上限从技能类里获取
private:
	void updateSkillCooldown(const std::string& name, float dt);
	/*
	float _timeCount1skill;
	bool _ready1skill;
	float _timeCount2skill;
	bool _ready2skill;
	*/
	//直接触发技能或者动画的逻辑操作。

	void activeSkill(const std::string& positionName);
	void activeAnimate(const std::string& animateName);
public:
	//初始化操作
	static M_Player* create(const std::string& filename);
	void addSkill(const std::string& positionName, M_pSkill* skill);
	//动态操作&&实体行为
	void handleAction(AdvenTriEnum::PlayerAction action);
	//以下为实体类的操作集，由PlayerSate访问时可以直接使用操作。
	//attack的外部调用接口,实际上是对技能的调用。
	void attack();
	//parry的外部接口,实际上是对技能的调用。
	void parry();
	//直接发动Dash技能。
	void dash();
	//只有在真的被Hurt的时候才会调用该方法，直接处理受伤特效，减去生命，播放动画，附加状态等。
	void doHurt();
	void kill();
	//直接使用物品，包括调用物品的使用方法，对物品数量进行更新，播放使用的动画。
	void useItem();
	void changeItem();
	void dropItem();
	//直接操作物品，包括调用互动物品的操作函数，播放互动的动画，和互动的逻辑更新。
	void operate();
	//结束的操作和函数
	inline void destroy();
	//update函数
	void update(float dt);
	//getters&setters
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

	//尚未实现的函数，和场景类互动函数结合。
	bool canOperate()
	{
		return false;
	}
	bool canUseItem()
	{
		return false;
	}
	bool canBlink()
	{
		return false;
	}
	//尚未实现的函数，可能需要结合UI等，目前不清楚实际形式。
	void blink()
	{
		activeSkill("Blink");
		return;
	}
	void dashAttack()
	{
		activeSkill("DashAttack");
		return;
	}
};

#endif