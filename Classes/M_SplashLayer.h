#ifndef __M_SPLASHSCENE__
#define __M_SPLASHSCENE__

#include "cocos2d.h"

class SD_SplashLayer;
class SD_GameLayer;
class Sys_Scene;

using namespace cocos2d;

class M_SplashLayer:public Layer
{
	friend class Sys_Scene;
private:
	SD_GameLayer* sdGameLayer;
public:
	static Scene* createSplashScene(SD_SplashLayer*, SD_GameLayer*);
	static M_SplashLayer* create(SD_SplashLayer*, SD_GameLayer*);
	bool initSplashLayer(SD_SplashLayer*, SD_GameLayer*);
public:
	void onEnter();
	void finishSplash(float dt);
};

#endif