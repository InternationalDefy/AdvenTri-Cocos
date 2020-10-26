#ifndef __CONTROLLER_PLAYER_H__	
#define __CONTROLLER_PLAYER_H__

#include "Ctrl_Base.h"

#define KEY_MOVE_RIGHT EventKeyboard::KeyCode::KEY_D
#define KEY_MOVE_LEFT EventKeyboard::KeyCode::KEY_A
#define KEY_MOVE_UP EventKeyboard::KeyCode::KEY_W
#define KEY_MOVE_DOWN EventKeyboard::KeyCode::KEY_S
#define KEY_SKILL_SHIFT EventKeyboard::KeyCode::KEY_LEFT_SHIFT
#define KEY_SKILL_SPACE EventKeyboard::KeyCode::KEY_SPACE

using namespace cocos2d;

class Entity;
class SD_pCtrl;
class Ctrl_Camera;

class Ctrl_Player : public Node
{
	friend class Ctrl_Camera;
private:
	float _force;
	float _vAngular;

	void keyDown(EventKeyboard::KeyCode keyCode, Event* event);
	void keyUp(EventKeyboard::KeyCode keyCode, Event* event);
	void mouseMove(Event* event);
	void mouseDown(Event* event);
	void mouseUp(Event* event);
	void mouseScoll(Event* event);
	/*
	void HandleMouseMove();

	void downHandleMouseRight();
	void upHandleMouseRight();

	void downHandleMouseLeft();
	void upHandleMouseLeft();
	*/
	void updateMouse();
	void updateRotation();
	void updateMovement();
	void updateSkill();
	void updateViewPosition();

	void initData();

	bool _keyPressed[EventKeyboard::KeyCode::KEY_PLAY];
	bool _mouseRightDown;
	bool _mouseLeftDown;
	Vec2 _mousePos;
	Vec2 _GLmousePos;
	Vec2 _zeroPosition;
	
	Ctrl_Camera* _cController;
	//int changeKeyCodeToNumber(EventKeyboard::KeyCode keyCode);

	EventListenerMouse* _mouseListener;
	EventListenerKeyboard* _keyboardListener;
	
	bool _locked;
	//以下为对Dubuff提供的外部方法。
public:
	Vec2 getDashVec2()
	{
		float x(0); float y(0);
		if (_keyPressed[EventKeyboard::KeyCode::KEY_W]) y += 0.7f;
		if (_keyPressed[EventKeyboard::KeyCode::KEY_S]) y -= 0.7f;
		if (_keyPressed[EventKeyboard::KeyCode::KEY_D]) x += 0.7f;
		if (_keyPressed[EventKeyboard::KeyCode::KEY_A]) x -= 0.7f;
		return (Vec2(x, y));
	}
public:
	void setFrozen()
	{
		_frozen = 0.2f;
		return;
	}
	void setUnFrozen()
	{
		_frozen = 1.0f;
		return;
	}
	void setCursed()
	{
		_cursed = -1.0f;
		return;
	}
	void setUncursed()
	{
		_cursed = 1.0f;
		return;
	}
private:
	Entity* _entity;
public:
	Entity* getEntity()
	{
		return _entity;
	}
	void setEntity(Entity* x)
	{
		if (_entity)
		{
			log("Already Has An Entity");
			return;
		}
		_entity = x;
		return;
	}
private:
	float _frozen;
	float _cursed;

public:
	static Ctrl_Player* create();

	void active();

	void update(float dt);
	/*
	void lockUpdate()
	{
		_locked = TRUE;
	}
	void unlockUpdate()
	{
		_locked = FALSE;
	}
	*/
	void assignListener();
	//void setEntity(Entity* entity);
	void setVangular(float x){ _vAngular = x; }
	void setForce(float x){ _force = x; }
	void setCameraController(Ctrl_Camera* cameraController);

};

#endif