#ifndef __M_ITEM_STATE__
#define __M_ITEM_STATE__
#include "cocos2d.h"
using namespace cocos2d;

class Sys_Item;
class M_Player;

class M_ItemState : public Node
{
public:
	CREATE_FUNC(M_ItemState);
private:
	Sys_Item* _system;
private:
	std::string _itemName;
	std::string _entityName;
private:
	bool init();
	ActionInstant* _dropFunc;
	FiniteTimeAction* _useFunc;
private:
	float _useTime;
	Animate* _pickUp;
	Animate* _use;
private:
	M_Player* _player;
public:
	void drop();
	void use();
	//init setters&&getters
public:
	M_Player* getPlayer();
public:
	void setUseTime(float x){ _useTime = x; }
	void setPickUpAnimate(Animate* x){ _pickUp = x; }
	void setUseAnimate(Animate* x){ _use = x; }
	void setDropFunc(ActionInstant* x){ _dropFunc = x; }
	void setItemName(const std::string x){ _itemName = x; }
	std::string getItemName(){ return _itemName; }
	void setEntityName(const std::string x){ _entityName = x; }
	void setSystem(Sys_Item* x){ _system = x; }
	void setPlayer(M_Player* x){ _player = x; }
	void addUseFunc(FiniteTimeAction* x);
};

#endif