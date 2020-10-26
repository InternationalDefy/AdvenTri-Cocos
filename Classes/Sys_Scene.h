#ifndef __SYS_SCENE__
#define __SYS_SCENE__

#include "cocos2d.h"
#include "DataBase.h"

class DB_GameLayer;
class DB_SplashLayer;
class DB_Scene;
class M_ScriptParser;
class M_GameLayer;
class M_SplashLayer;

using namespace cocos2d;

class Sys_Scene :public Ref
{
	friend class M_GameLayer;
	friend class M_SplashLayer;
private:
	DB_GameLayer* _dbGameLayer;
	DB_SplashLayer* _dbSplashScene;
	DB_Scene* _dbScene;
	M_ScriptParser* _scriptParser;

	void initGameLayer(M_GameLayer*, SD_GameLayer*);

	void init();
public:
	Scene* getScene(const std::string& sceneName);
	Scene* getSplashScene(SD_SplashLayer*,SD_GameLayer*);
	Scene* getGameScene(SD_GameLayer*);

	void nextScene(const std::string& sceneName);

	static Sys_Scene* getInstance();
	static Sys_Scene* create();
};

#endif