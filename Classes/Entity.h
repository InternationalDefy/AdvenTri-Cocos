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
	//Tag则是（！每个场景中）单个实体的标识，由场景方法给出，各不相同。
	std::string EntityTAG;
	//EntityState表示的是存在与否的状态的数据记录，存档系统沟通时使用。
	//0无1有
	int EntityState;
public:
	virtual void initEntity();
public:
	static Entity* create(const std::string& filename);
	
	virtual void destroy();
	virtual void update(float delta);
//以下方法处理Animation
protected:
	bool _animationRunning;
	FiniteTimeAction* _currentAnimation;
	M_AnimationPack* _animationPack;
public:
	void setAnimationPack(M_AnimationPack*);
	void animationEndCallback();
	void runAnimation(const std::string& key);
//以上
//以下方法处理实体阴影
protected:
	bool _enableShadow;
	M_Shadow* _shadowSprite;
public:
	M_Shadow* getShadow();
	/*
	@param float height:光源高度相对于实体位置
	@param float depth:阴影的深度，实体与阴影的z轴距离。
	*/
	void setShadow(float height, float depth);
//以上
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