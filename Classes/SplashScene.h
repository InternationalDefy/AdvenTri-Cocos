#ifndef __SplashScene__
#define __SplashScene__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class SplashScene : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void onEnter();

	void finishSplash(float dt);

	// implement the "static create()" method manually
	CREATE_FUNC(SplashScene);
};

#endif /* defined(__stickerPuzzle__SplashScene__) */
