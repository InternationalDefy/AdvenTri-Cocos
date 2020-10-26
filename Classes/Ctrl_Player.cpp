#include "Ref2Controller.h"
#include "Ctrl_Camera.h"

using namespace cocos2d;

Ctrl_Player* Ctrl_Player::create()
{
	Ctrl_Player *controllerPlayer = new (std::nothrow) Ctrl_Player();
	if (controllerPlayer)
	{
		controllerPlayer->autorelease();
		controllerPlayer->initData();
		return controllerPlayer;
	}
	CC_SAFE_DELETE(controllerPlayer);
	return nullptr;
}
void Ctrl_Player::initData()
{
	for (int i = 0; i <= 165; ++i)
	{
		_keyPressed[i] = FALSE;
	}
	_mouseLeftDown = FALSE;
	_mouseRightDown = FALSE;
	_cController = NULL;
	_zeroPosition = Vec2(0, 0);
	_locked = FALSE;
	_frozen = 1;
	_cursed = 1;
	_entity = NULL;
}
void Ctrl_Player::active()
{
	if (!getEntity())
	{
		auto k = "Player Ctrl_Base 's Entity UNFOUND!";
		log(k);
		return;
	}
	assignListener();
	return;
}
void Ctrl_Player::assignListener()
{
	_mouseListener = EventListenerMouse::create();
	_keyboardListener = EventListenerKeyboard::create();
	auto layer = this->getEntity()->getParent();
	if (!layer)
	{
		log("Ctrl_Base's Parent Layer UNFOUND!");
	}
	_mouseListener->onMouseDown = CC_CALLBACK_1(Ctrl_Player::mouseDown, this);
	_mouseListener->onMouseMove = CC_CALLBACK_1(Ctrl_Player::mouseMove, this);
	_mouseListener->onMouseUp = CC_CALLBACK_1(Ctrl_Player::mouseUp, this);
	_mouseListener->onMouseScroll = CC_CALLBACK_1(Ctrl_Player::mouseScoll, this);
	_keyboardListener->onKeyPressed = CC_CALLBACK_2(Ctrl_Player::keyDown, this);
	_keyboardListener->onKeyReleased = CC_CALLBACK_2(Ctrl_Player::keyUp, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, layer);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_keyboardListener, layer);
}
void Ctrl_Player::mouseMove(Event* event)
{
	EventMouse* eventMouse = (EventMouse*)event;
	_GLmousePos = Vec2(eventMouse->getCursorX(), eventMouse->getCursorY());
}
void Ctrl_Player::mouseUp(Event* event)
{
	EventMouse* eventMouse = (EventMouse*)event;
	int btn = eventMouse->getMouseButton();
	if (btn == 0)
	{
		_mouseLeftDown = FALSE;
	}
	else if (btn == 1)
	{
		_mouseRightDown = FALSE;
	}
}
void Ctrl_Player::mouseScoll(Event* event)
{
	if (!_cController)
	{
		log("No!!!!!!!!!!!!");
		return;
	}
	EventMouse* eventMouse = (EventMouse*)event;
	float i = eventMouse->getScrollY();
	if (i < 0)
	{
		_cController->moveCameraZ(0.3f, -155.0f);
		return;
	}
	_cController->moveCameraZ(0.3f, 155.0f);
}
void Ctrl_Player::mouseDown(Event* event)
{
	EventMouse* eventMouse = (EventMouse*)event;
	int btn = eventMouse->getMouseButton();
	if (btn == 0)
	{
		_mouseLeftDown = TRUE;
	}
	else if (btn == 1)
	{
		_mouseRightDown = TRUE;
	}
}
void Ctrl_Player::keyUp(EventKeyboard::KeyCode keyCode, Event* event)
{
	_keyPressed[keyCode] = FALSE;
}
void Ctrl_Player::keyDown(EventKeyboard::KeyCode keyCode, Event* event)
{	
	_keyPressed[keyCode] = TRUE;
}
void Ctrl_Player::update(float dt)
{
	if (!_locked)
	{
		updateMouse();
		updateRotation();
		updateMovement();
		updateSkill();
	}
}
void Ctrl_Player::updateMouse()
{	
	if (_cController)
		_mousePos = Vec2(
		_GLmousePos.x * _cController->_radio + _zeroPosition.x,
		_GLmousePos.y * _cController->_radio + _zeroPosition.y);
	else
		_mousePos = _GLmousePos;
}
void Ctrl_Player::updateRotation()
{
	getEntity()->setRotation(-atan2f(
		_mousePos.y - getEntity()->getPositionY(),
		_mousePos.x - getEntity()->getPositionX())
		* 360 / 6.28f);
}
void Ctrl_Player::updateMovement()
{
	if (_keyPressed[KEY_MOVE_RIGHT]) getEntity()->getPhysicsBody()->applyImpulse(_frozen*_cursed*Vec2(_force, 0.0f));
	if (_keyPressed[KEY_MOVE_LEFT]) getEntity()->getPhysicsBody()->applyImpulse(_frozen*_cursed*Vec2(-_force, 0.0f));
	if (_keyPressed[KEY_MOVE_UP]) getEntity()->getPhysicsBody()->applyImpulse(_frozen*_cursed*Vec2(0.0f, _force));
	if (_keyPressed[KEY_MOVE_DOWN]) getEntity()->getPhysicsBody()->applyImpulse(_frozen*_cursed*Vec2(0.0f, -_force));
}
void Ctrl_Player::updateSkill()
{
	if (_keyPressed[KEY_SKILL_SHIFT] && _mouseLeftDown)
	{
		//dynamic_cast<M_Player*> (getEntity())->activeSkill("Skill1"); 
		dynamic_cast<M_Player*> (getEntity())->handleAction(AdvenTriEnum::PlayerAction::P_ACTION_SKILL1);
		return;
	}
	if (_mouseLeftDown)
	{
		//	dynamic_cast<M_Player*> (getEntity())->activeSkill("SimpleAttack");
		dynamic_cast<M_Player*> (getEntity())->handleAction(AdvenTriEnum::PlayerAction::P_ACTION_ATTACK);
		return;
	}
	if (_keyPressed[KEY_SKILL_SHIFT] && _mouseRightDown)
	{
		dynamic_cast<M_Player*> (getEntity())->handleAction(AdvenTriEnum::PlayerAction::P_ACTION_SKILL2);
		return;
	}
	if (_mouseRightDown)
	{
		dynamic_cast<M_Player*> (getEntity())->handleAction(AdvenTriEnum::PlayerAction::P_ACTION_PARRY);
		return;
	}
	if (_keyPressed[KEY_SKILL_SPACE])
	{
		dynamic_cast<M_Player*> (getEntity())->handleAction(AdvenTriEnum::PlayerAction::P_ACTION_DASH);
		return;
	}
}
void Ctrl_Player::setCameraController(Ctrl_Camera* cameraController)
{
	if (!cameraController)
	{
		log("NOOOOOOOOOOOOOOOOOOOOOO!");
	}
	_cController = cameraController;
}