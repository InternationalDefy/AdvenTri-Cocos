#ifndef __M_ITEMENTITY__
#define __M_ITEMENTITY__

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

class Ctrl_Base;
class M_Player;
class M_CallbackParser;
class M_DispatchParser;

class M_ItemEntity :public Entity
{
private:
	virtual void initEntity();
public:
	static M_ItemEntity* M_ItemEntity::create(const std::string& filename)
	{
		M_ItemEntity *entity = new (std::nothrow) M_ItemEntity();
		if (entity && entity->initWithFile(filename))
		{
			entity->initEntity();
			entity->autorelease();
			return entity;
		}
		CC_SAFE_DELETE(entity);
		return nullptr;
	}

private:
	FiniteTimeAction* _flyingEndCallfunc;
	float _timeExist;
	Animate* _throwAnimate;
	Ctrl_Base* _flyController;
	Ctrl_Base* _dropController;
public:
	void flyEnd();
	void dropByPlayer(M_Player* player);
	void dropByEnemy(Vec2 pos);
public:
	void update(float dt);
private:
	void flyEndOnEnd();

private:
	std::string _itemName;
	std::string _itemState;

public:
	std::string getItemName(){ return _itemName; }
	std::string getStateName(){ return _itemState; }
	//settters
	void setItemName(const std::string& x){ _itemName = x; }
	void setItemStateName(const std::string& x){ _itemState = x; }
	void setFlyController(Ctrl_Base* x){ _flyController = x; }
	void setDropController(Ctrl_Base* x){ _dropController = x; }
	void setThrowAnimate(Animate* x){ _throwAnimate = x; }
	void setExistingTime(float x){ _timeExist = x; }
	void setFlyingEndFunc(FiniteTimeAction* x);
};

#endif