#include "Ref2SceneSystem.h"

using namespace cocos2d;

void Sys_Scene::init()
{
	_dbGameLayer = DB_GameLayer::getInstance();
	_dbScene = DB_Scene::getInstance();
	_dbSplashScene = DB_SplashLayer::getInstance();
	_scriptParser = M_ScriptParser::getInstance();
}
//这个函数完成的比较粗糙，需要先测试GetScene是否正确再考虑之。
void Sys_Scene::nextScene(const std::string& sceneName)
{
	if (Director::getInstance()->getRunningScene())
	{
		Director::getInstance()->getRunningScene()->runAction(FadeOut::create(0.3f));
	}
	auto newScene = getScene(sceneName);
	Director::getInstance()->replaceScene(TransitionFade::create(0.3f,newScene));
}
/*
getScene(std::string)方法得到的是一个SplashScene，
该SplashScene由脚本控制器从SD_Scene中选择而出，完成了自身的创建。
并且在该SplashScene的生成方法中设置有一个生成对应的GameLayer的函数。
该函数知道要生成何种GameLayer，但是由于生成GameLayer需要较长的时间所以要在先展示SplashScene之后实现。
GameLayer对应的Scene中应该包含对应的UI方案。但SplashScene没有UI方案。
*/
Scene* Sys_Scene::getScene(const std::string& sceneName)
{
	SD_Scene* scenesd = _dbScene->getSceneSD(sceneName);
	int i = 0;
	while (i != scenesd->getNumberOfSplashScene() ||
		!_scriptParser->handleJudgeScript(&scenesd->getSplashSceneItems()->at(i).scripts))
		i++;
	if (i = scenesd->getNumberOfSplashScene())
		log("Havnet a TRUE script!");
	std::string splash = scenesd->getSplashSceneItems()->at(i).itemName;

	i = 0;
	while (i != scenesd->getNumberOfGameLayer() ||
		!_scriptParser->handleJudgeScript(&scenesd->getGameLayerItems()->at(i).scripts))
		i++;
	if (i = scenesd->getNumberOfGameLayer())
		log("Havnet a TRUE script!");
	std::string Glayer = scenesd->getGameLayerItems()->at(i).itemName;

	SD_SplashLayer* splashsd = _dbSplashScene->getSplashSceneSD(splash);
	SD_GameLayer* glayersd = _dbGameLayer->getGameLayerSD(Glayer);
	Scene* splashScene = getSplashScene(splashsd, glayersd);

	return splashScene;
}

void Sys_Scene::initGameLayer(M_GameLayer* l, SD_GameLayer* s)
{
	if (!l->init(s))
		log("Init Failed!");
}
Scene* Sys_Scene::getSplashScene(SD_SplashLayer* sds, SD_GameLayer* sdg)
{
	return M_SplashLayer::createSplashScene(sds, sdg);
}
Scene* Sys_Scene::getGameScene(SD_GameLayer* sd)
{
	auto sc = M_GameLayer::getScene(sd);
	
	sc->getPhysicsWorld()->setDebugDrawMask(TRUE);

	return sc;
}

CREATE_DB(Sys_Scene);