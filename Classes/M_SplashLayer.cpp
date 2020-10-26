#include "Ref2SceneSystem.h"

using namespace cocos2d;

Scene* M_SplashLayer::createSplashScene(SD_SplashLayer* sds, SD_GameLayer* sdg)
{
	auto scene = Scene::create();
	auto layer = M_SplashLayer::create(sds,sdg);
	scene->addChild(layer);
	return scene;
}
bool M_SplashLayer::initSplashLayer(SD_SplashLayer* sds, SD_GameLayer* sdg)
{
	if (!Layer::init())
	{
		return FALSE;
	}
	sdGameLayer = sdg;

	for (auto i = 0; i < sds->getNumberOfSprite(); ++i)
	{
		Sprite* sp = Sprite::create(sds->getItems()->at(i).image);
		sp->setPosition3D(sds->getItems()->at(i).position);
		if (sds->getItems()->at(i).enableAction)
		{
			M_ActionHandler::getInstance()->getAction(sp,
				sds->getItems()->at(i).actionType, sds->getItems()->at(i).actionParam);
		}
		if (sds->getItems()->at(i).enableListenerSet)
		{
			Sys_Event::getInstance()->addListenerSetTo(sp, sds->getItems()->at(i).listenerSet);
		}
		addChild(sp, sds->getItems()->at(i).localZorder);
	}
}
M_SplashLayer* M_SplashLayer::create(SD_SplashLayer* sds, SD_GameLayer* sdg)
{
	M_SplashLayer* sp = new(std::nothrow) M_SplashLayer();
	if (sp&&sp->initSplashLayer(sds, sdg))
	{
		return sp;
	}
	CC_SAFE_DELETE(sp);
	return NULL;
}
void M_SplashLayer::onEnter()
{
	Layer::onEnter();
	this->scheduleOnce(schedule_selector(M_SplashLayer::finishSplash), 0.3f);
}
void M_SplashLayer::finishSplash(float dt)
{
	this->runAction(FadeOut::create(dt));
	Director::getInstance()->replaceScene(Sys_Scene::getInstance()->getGameScene(sdGameLayer));
}