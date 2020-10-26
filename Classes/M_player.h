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
	//updateSkillCoolDownӦ����State��ִ�У�
	//void updateSkillCoolDown();
	int _hp;
	int _Maxhp;
private:
	void logicUpdate(float dt);
public:
	Sprite* _parryNode;
	//���´����˺�Debuff��״̬
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
	//�ⲿset���ʼ����ʱ������ΪĬ��ֵ����hurt����֮ǰ�����ã�ʹ�ú����û�Ĭ��ֵ��
	AdvenTriEnum::DamageType _onHurtType;
	float _onHurtDamage;

	//���´���hurt��skill��parry����ȴ��ʱ����
	void updateHurtingTime(float dt);
	
	float _hurtingTime;
	bool _hurting;

	Map<std::string, M_pSkill*> _skills;
	//?Ӧ�ò���Ҫ std::map<std::string, float> _skillLimit;
	std::map<std::string, float> _skillCoolDown;
	std::map<std::string, bool> _skillReady;
public:
	bool isSkillReady(const std::string& posName)
	{
		int i = 1;
		return _skillReady.at(posName);
	}
	//��ȴʱ�����޴Ӽ��������ȡ
private:
	void updateSkillCooldown(const std::string& name, float dt);
	/*
	float _timeCount1skill;
	bool _ready1skill;
	float _timeCount2skill;
	bool _ready2skill;
	*/
	//ֱ�Ӵ������ܻ��߶������߼�������

	void activeSkill(const std::string& positionName);
	void activeAnimate(const std::string& animateName);
public:
	//��ʼ������
	static M_Player* create(const std::string& filename);
	void addSkill(const std::string& positionName, M_pSkill* skill);
	//��̬����&&ʵ����Ϊ
	void handleAction(AdvenTriEnum::PlayerAction action);
	//����Ϊʵ����Ĳ���������PlayerSate����ʱ����ֱ��ʹ�ò�����
	//attack���ⲿ���ýӿ�,ʵ�����ǶԼ��ܵĵ��á�
	void attack();
	//parry���ⲿ�ӿ�,ʵ�����ǶԼ��ܵĵ��á�
	void parry();
	//ֱ�ӷ���Dash���ܡ�
	void dash();
	//ֻ������ı�Hurt��ʱ��Ż���ø÷�����ֱ�Ӵ���������Ч����ȥ���������Ŷ���������״̬�ȡ�
	void doHurt();
	void kill();
	//ֱ��ʹ����Ʒ������������Ʒ��ʹ�÷���������Ʒ�������и��£�����ʹ�õĶ�����
	void useItem();
	void changeItem();
	void dropItem();
	//ֱ�Ӳ�����Ʒ���������û�����Ʒ�Ĳ������������Ż����Ķ������ͻ������߼����¡�
	void operate();
	//�����Ĳ����ͺ���
	inline void destroy();
	//update����
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

	//��δʵ�ֵĺ������ͳ����໥��������ϡ�
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
	//��δʵ�ֵĺ�����������Ҫ���UI�ȣ�Ŀǰ�����ʵ����ʽ��
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