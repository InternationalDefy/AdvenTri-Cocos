#include "Ctrl_Camera.h"
#include "Ctrl_Player.h"
#include "Entity.h"

using namespace cocos2d;

Ctrl_Camera* Ctrl_Camera::create()
{
	Ctrl_Camera* pRet = new Ctrl_Camera();
	if (pRet)
	{
		pRet->autorelease();
		pRet->initData();
		return pRet;
	}
	return nullptr;
}
Ctrl_Camera* Ctrl_Camera::create(Scene* scene)
{
	Ctrl_Camera* pRet = new Ctrl_Camera();
	if (pRet)
	{
		pRet->autorelease();
		pRet->initData();
		pRet->initCameraDefault(scene);
		return pRet;
	}
	return nullptr;
}
void Ctrl_Camera::initCameraDefault(Scene* scene)
{
	if (!scene->getDefaultCamera())
	{
		log("This Scene Hasnt A Camera!");
	}
	setCamera(scene->getDefaultCamera());
}
void Ctrl_Camera::initCameraWithID(Scene* scene, int id)
{
	if (!scene->getCameras().at(id - 1))
	{
		log("Camera NO %d UNFOUND!",id);
	}
	setCamera(scene->getCameras().at(id - 1));
}
void Ctrl_Camera::initData()
{
	_cameraMoving = FALSE;
	_cameraZmoving = FALSE;
	_moveX = 0;
	_moveY = 0;
	_locked = FALSE;
	_windowSizeX = WINDOWSIZE_WIDTH;
	_windowSizeY = WINDOWSIZE_HEIGHT; 
	_heightBefore = 0;
	_heightNow = 0;
	_radio = 1;
	//_limitX = 0;
	//_limitY = 0;
	_limitRightX = FALSE;
	_limitLeftX = FALSE;
	_limitUpY = FALSE;
	_limitDownY = FALSE;

}
void Ctrl_Camera::setCamera(Camera* camera)
{
	_camera = camera;
}
void Ctrl_Camera::setPlayerController(Ctrl_Player* playerController)
{
	if (!playerController)
	{
		log("NOOO!!!!!!!!!!!!");
	}
	_pController = playerController;
}

void Ctrl_Camera::moveCameraBy(float dt, Vec2 by)
{
	if (_cameraMoving)
	{
		return;
	}
	
	if (_camera)
	{
		_cameraMoving = TRUE;
		_pController->_zeroPosition.x += by.x;
		_pController->_zeroPosition.y += by.y;
		_camera->runAction(Sequence::create(MoveBy::create(dt, by),
			CallFunc::create(std::bind(&Ctrl_Camera::actionFinishCallback, this)),
			NULL));
	}
	else
	{
		return;
	}
	
}
void Ctrl_Camera::moveCameraTo(float dt, Vec2 to)
{
	if (_cameraMoving)
	{
		return;
	}
	if (_camera)
	{
		//_pController->_locked = TRUE;
		_cameraMoving = TRUE;
		_pController->_zeroPosition.x += to.x;
		_pController->_zeroPosition.x -= _camera->getPositionX();
		_pController->_zeroPosition.y += to.y;
		_pController->_zeroPosition.y -= _camera->getPositionY();
		_camera->runAction(Sequence::create(MoveTo::create(dt, to),
			CallFunc::create(std::bind(&Ctrl_Camera::actionFinishCallback, this)),
			NULL));
	}
	else
	{
		return;
	}
}
void Ctrl_Camera::moveCameraZ(float dt, float z)
{
	if (_cameraZmoving)
	{
		return;
	}
	if (_radio < 0.52 && z < 0)
	{
		return;
	}
	if (_radio > 1.98 && z > 0)
	{
		return;
	}
	if (_camera)
	{
		_cameraZmoving = TRUE;
		_heightBefore = _camera->getPositionZ();
		_camera->runAction(Sequence::create(MoveBy::create(dt, Vec3(0, 0, z)),
			CallFunc::create(std::bind(&Ctrl_Camera::movingZfinishCallback, this)),
			NULL));
		return;
	}
	else
	{
		return;
	}
}
void Ctrl_Camera::actionFinishCallback()
{
	_cameraMoving = FALSE;
	return;
}
void Ctrl_Camera::movingZfinishCallback()
{
	_cameraZmoving = FALSE;
	//_pController->_locked = FALSE;
	_heightNow = _camera->getPositionZ();
	float _radioBefore = _radio;
	_radio *= _heightNow / _heightBefore;
	_windowSizeX *= _radio / _radioBefore;
	_windowSizeY *= _radio / _radioBefore;

	//_pController->_zeroPosition.x += ((_radioBefore - _radio) * _camera->getPositionX());
	//_pController->_zeroPosition.y += ((_radioBefore - _radio) * _camera->getPositionY());
	_pController->_zeroPosition.x =
		_camera->getPositionX()*(1.0f - _radio / _radioBefore)
		+ _pController->_zeroPosition.x*(_radio / _radioBefore);
	_pController->_zeroPosition.y =
		_camera->getPositionY()*(1.0f - _radio / _radioBefore)
		+ _pController->_zeroPosition.y*(_radio / _radioBefore);
	return;
}
void Ctrl_Camera::update(float dt)
{
	if (!_locked) updateCameraMoving(dt);
}
bool Ctrl_Camera::positionInCenter(Vec2 pos)
{
	if (abs(pos.x - _camera->getPositionX()) < CENTER_WIDTH*0.5f
		&&abs(pos.y - _camera->getPositionY()) < CENTER_HEIGHT*0.5f)
	{
		return true;
	}
	else return false;
}
void Ctrl_Camera::highSpeedMove(Vec2 pos)
{/*
	float deltaX = pos.x - _camera->getPositionX();
	float deltaY = pos.y - _camera->getPositionY();
	float sqr = sqrt(deltaX*deltaX + deltaY*deltaY);
		
	Vec2 by = Vec2(
		(std::roundf(10 *
		abs(_pController->getEntity()->getPhysicsBody()->getVelocity().x)
		/ _pController->getEntity()->getPhysicsBody()->getVelocityLimit()) / 10
		+0.05)
		*MOVE_PER_FRAME * deltaX / sqr,
		(std::roundf(10 *
		abs(_pController->getEntity()->getPhysicsBody()->getVelocity().y)
		/ _pController->getEntity()->getPhysicsBody()->getVelocityLimit()) / 10
		+0.05)
		*MOVE_PER_FRAME * deltaY / sqr);
	
	_pController->_zeroPosition.x += by.x;
	_pController->_zeroPosition.y += by.y;

	_camera->setPosition(Vec2(
		_camera->getPositionX() + by.x,
		_camera->getPositionY() + by.y));
		*/
}
/*
void Ctrl_Camera::lowSpeedMove(Vec2 pos)
{
	_camera->setPositionX(pos.x);
	_camera->setPositionY(pos.y);
	_pController->_zeroPosition.x += pos.x;
	_pController->_zeroPosition.x -= _camera->getPositionX();
	_pController->_zeroPosition.y += pos.y;
	_pController->_zeroPosition.y -= _camera->getPositionY();
	return;
}
*/
void Ctrl_Camera::updateCameraMoving(float dt)
{
	if (_cameraMoving)
	{
		return;
	}
	//目前使用最原始方案，直接移动法。
	setCameraTo(_pController->getEntity()->getPosition());
	
	//方案3：跟踪固定速度法
	/*
	if (!positionInCenter(_pController->getEntity()->getPosition()))
	{
		highSpeedMove(_pController->getEntity()->getPosition());
		return;
	}
	*/
	//方案2：边缘切换
	/*
	if (!_limitRightX&&
		_pController->getEntity()->getPositionX() > _camera->getPositionX() + _windowSizeX*0.5)
		_moveX = _windowSizeX;
	else if (!_limitLeftX&&
		_pController->getEntity()->getPositionX() < _camera->getPositionX() - _windowSizeX*0.5)
		_moveX = -_windowSizeX;
	else _moveX = 0;
	if (!_limitUpY&&
		_pController->getEntity()->getPositionY() > _camera->getPositionY() + _windowSizeY*0.5)
		_moveY = _windowSizeY;
	else if (!_limitDownY&&
		_pController->getEntity()->getPositionY() < _camera->getPositionY() - _windowSizeY*0.5)
		_moveY = -_windowSizeY;
	else _moveY = 0;
	if (_moveX != 0 || _moveY != 0)
	{
		moveCameraBy(WINDOWMOVE_TIME, Vec2(_moveX, _moveY));
		_moveX = 0; _moveY = 0;
	}
	*/
}

void Ctrl_Camera::setCameraTo(Vec2 to)
{
	//应当考虑边缘问题？不必？因为可以用实体边缘？
	_pController->_zeroPosition.x += to.x;
	_pController->_zeroPosition.x -= _camera->getPositionX();
	_pController->_zeroPosition.y += to.y;
	_pController->_zeroPosition.y -= _camera->getPositionY();
	_camera->setPosition(_pController->getEntity()->getPosition());
	return;
}
void Ctrl_Camera::setBorderLimited(bool x1,bool x2,bool y1,bool y2)
{
	_limitLeftX = x1;
	_limitRightX = x2;
	_limitUpY = y1;
	_limitDownY = y2;
}