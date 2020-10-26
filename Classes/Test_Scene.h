#ifndef __TEST_SCENE__
#define __TEST_SCENE__

#include "cocos2d.h"

using namespace cocos2d;

class Test_Scene : public Ref
{
public:
	/*
	��ȡ����һ����Test_Layer����ͱ༭����Layer 
	��������Scene��ʹ�ø�GameLayer��Ĭ��UI������Test_Layer����Ϊ��UI
	*/
	Scene* testSceneGameLayer(const std::string& name,bool testDataBase=false);

	Test_Scene::Test_Scene();

	void testDataBase();

public:
	//������������
	static Test_Scene* getInstance();
	static Test_Scene* create();

public:
	Test_Layer* testLayer;

};

#endif 