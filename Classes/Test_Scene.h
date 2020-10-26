#ifndef __TEST_SCENE__
#define __TEST_SCENE__

#include "cocos2d.h"

using namespace cocos2d;

class Test_Scene : public Ref
{
public:
	/*
	获取的是一个被Test_Layer管理和编辑过的Layer 
	所创建的Scene，使用该GameLayer的默认UI，或经由Test_Layer设置为无UI
	*/
	Scene* testSceneGameLayer(const std::string& name,bool testDataBase=false);

	Test_Scene::Test_Scene();

	void testDataBase();

public:
	//单例创建函数
	static Test_Scene* getInstance();
	static Test_Scene* create();

public:
	Test_Layer* testLayer;

};

#endif 