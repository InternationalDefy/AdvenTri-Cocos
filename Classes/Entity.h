#ifndef __ENTITY_H__	
#define __ENTITY_H__

#define HURT_TIME 1.0f
#define DEBUFF_LIMIT 2.0f

#include "cocos2d.h"

#include "M_EffectSprite.h"

class Ctrl_Base;
class Ctrl_Player;
class M_DispatchParser;
class M_CallbackParser;
class M_AnimationPack;
class M_Shadow;

using namespace cocos2d;

class Entity : public M_EffectSprite
{
protected:
	Ctrl_Base* _controller;
	Ctrl_Player* _pCtrl;
	std::vector<M_DispatchParser*> _dispatchParser;
	std::vector<M_CallbackParser*> _callbackParser;
public:
	//Tag���ǣ���ÿ�������У�����ʵ��ı�ʶ���ɳ�������������������ͬ��
	std::string EntityTAG;
	//EntityState��ʾ���Ǵ�������״̬�����ݼ�¼���浵ϵͳ��ͨʱʹ�á�
	//0��1��
	int EntityState;
public:
	virtual void initEntity();
public:
	static Entity* create(const std::string& filename);
	
	virtual void destroy();
	virtual void update(float delta);
//���·�������Animation
protected:
	bool _animationRunning;
	FiniteTimeAction* _currentAnimation;
	M_AnimationPack* _animationPack;
public:
	void setAnimationPack(M_AnimationPack*);
	void animationEndCallback();
	void runAnimation(const std::string& key);
//����
//���·�������ʵ����Ӱ
protected:
	bool _enableShadow;
	M_Shadow* _shadowSprite;
public:
	M_Shadow* getShadow();
	/*
	@param float height:��Դ�߶������ʵ��λ��
	@param float depth:��Ӱ����ȣ�ʵ������Ӱ��z����롣
	*/
	void setShadow(float height, float depth);
//����
public:
	void setController(Ctrl_Base* controller);
	void setController(Ctrl_Player* controller);
	void activeController();
	void activepCtrl();

	virtual void addToScene(Layer* layer,int zOrder);
	
	void assignEventListener();

	virtual void removeFromParent();
	void pushDispatchParser(M_DispatchParser*);
	void pushCallbackParser(M_CallbackParser*);

	//getters&setters
	Ctrl_Base* getController();
	Ctrl_Player* getpCtrl();
};

#endif