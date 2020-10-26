#ifndef __TEST_LAYER__
#define __TEST_LAYER__

#include "cocos2d.h"

class M_GameLayer;

using namespace cocos2d;

class Test_Layer : public Ref
{
private:
	M_GameLayer* layer;
private:
	//以下函数是内部用来分配如何创建TestLayer的
	Layer* getTestLayer(const std::string& name);
	void editTestLayer(M_GameLayer* layer);
	void getEmptyLayer();
	//以下函数是和M_GameLayer的接口
public:
	Scene* getTestBoxStart(const std::string& name);
public:
	//单例创建函数
	static Test_Layer* Test_Layer::create();
	static Test_Layer* Test_Layer::getInstance();
	//测试时使用的按钮回调函数。
	void testBtnCallback(Ref*);
};


#endif