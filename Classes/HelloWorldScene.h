#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class M_Enemy;
class M_Player;
class M_LaEmojiPack;
class Ctrl_Player;
class Ctrl_Camera;
class Sys_Event;
class Sys_LaEmoji;

using namespace cocos2d;

class HelloWorld : public cocos2d::Layer
{
private:
	M_Player* t;

	M_Enemy* e;

	bool f = false;

	M_LaEmojiPack* pack;

	Ctrl_Player* pc;
	Ctrl_Camera* cc;
	Sprite* bg;

	Node* cameraNode;

	Sys_Event* sys;

	Sys_LaEmoji* lasys;
	
	bool _cameraFollow;

public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
	void update(float dt);
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
