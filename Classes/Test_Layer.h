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
	//���º������ڲ�����������δ���TestLayer��
	Layer* getTestLayer(const std::string& name);
	void editTestLayer(M_GameLayer* layer);
	void getEmptyLayer();
	//���º����Ǻ�M_GameLayer�Ľӿ�
public:
	Scene* getTestBoxStart(const std::string& name);
public:
	//������������
	static Test_Layer* Test_Layer::create();
	static Test_Layer* Test_Layer::getInstance();
	//����ʱʹ�õİ�ť�ص�������
	void testBtnCallback(Ref*);
};


#endif