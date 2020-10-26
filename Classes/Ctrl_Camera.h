#ifndef __M_CONTROLLER_CAMERA__	
#define __M_CONTROLLER_CAMERA__

#include "cocos2d.h"

#define WINDOWSIZE_WIDTH 1280
#define WINDOWSIZE_HEIGHT 720
#define WINDOWMOVE_TIME 0.7f

#define CENTER_WIDTH 128
#define CENTER_HEIGHT 72
#define MOVE_PER_FRAME 20

using namespace cocos2d;

class Ctrl_Player;

class Ctrl_Camera : public Node
{
	friend class Ctrl_Player;
private:
	
	bool positionInCenter(Vec2 pos);
	void highSpeedMove(Vec2 pos);

	Ctrl_Player* _pController;
	Camera* _camera;

	//void updateViewPosition();
	//void updateViewPosition();

	void setCamera(Camera* camera);

	bool _cameraMoving;
	bool _cameraZmoving;

	bool _locked;

	float _moveX;
	float _moveY;
	/* 
	2.11改：用border bool 取代border float
private:
	float _limitX;
	float _limitY;
	设置边缘大小
public:
	void Ctrl_Camera::setBorder(float x, float y)
	{
		_limitX = x;
		_limitY = y;
	}
	void setBorder(float x, float y);
	*/
	bool _limitRightX;
	bool _limitLeftX;
	bool _limitUpY;
	bool _limitDownY;
	
	float _heightBefore;
	float _heightNow;
	float _radio;

	float _windowSizeX;
	float _windowSizeY;
	
	void setCameraTo(Vec2 to);

	void updateCameraMoving(float dt);
	void actionFinishCallback();
	void movingZfinishCallback();

	void initCameraDefault(Scene* scene);
	void initCameraWithID(Scene* scene, int id);
	void initData();
	
public:
	static Ctrl_Camera* create();
	static Ctrl_Camera* create(Scene* scene);

	void update(float dt);
		
	void setPlayerController(Ctrl_Player* playerController);
	
	void setBorderLimited(bool left, bool right, bool up, bool down);

	void moveCameraTo(float delay, Vec2 posTo);
	void moveCameraBy(float delay, Vec2 posBy);
	void moveCameraZ(float delay, float z);

	float getCameraHeight(){ return _camera->getPositionZ(); }
	Vec2 getCameraPosition2D(){ return _camera->getPosition(); }
};

#endif