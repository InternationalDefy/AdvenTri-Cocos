#include "Ref2SceneSystem.h"
#include "Ref2TestCase.h"

Test_Layer* s_TestLayer;

Test_Layer* Test_Layer::getInstance()
{
	if (!s_TestLayer)
	{
		s_TestLayer = Test_Layer::create();
	}
	return s_TestLayer;
}
Test_Layer* Test_Layer::create()
{
	auto pRet = new Test_Layer();
	if (pRet)
	{
		pRet->retain();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
}
Scene* Test_Layer::getTestBoxStart(const std::string& name)
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	
	if (name == "Empty" || name == "Custom")
	{
		layer = M_GameLayer::create();
	}
	else
	{
		layer = M_GameLayer::create(DB_GameLayer::getInstance()->getGameLayerSD(name));
	}
	editTestLayer(layer);

	scene->addChild(layer);
	//����Ҳ�������´���UI�㣬���ǸĻ�������GetInstance��
	//ؽ��������
	auto uil = UI_Layer::create();
	scene->addChild(uil, 1);
	uil->setEntityLayer(layer);
	return scene;
}
/*
������ϵ��ɣ�
�ڸ�edit�������޸���Ҫ���Ե����ݡ�
*/
void Test_Layer::editTestLayer(M_GameLayer* layer)
{
	/*
	����ΪLaEmoji���ԡ�
	M_LaEmoji* la = Sys_LaEmoji::getInstance()->getLaEmoji("Test_LaEmoji_1");
	la->setPosition(Vec2(640, 360));
	layer->addChild(la, 1);
	la->enter();
	*/
	
	layer->tFuncAddEnemy("TestEnemy", Vec3(960, 360, 0), 1, "enemy1");

	//�������ܲ��淶������С������ʹ�á�
	auto b = Sprite::create("b1.jpg");
	b->setPosition(Vec2(640, 360));
	layer->addChild(b, 0);

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(Test_Layer::testBtnCallback, this));
	closeItem->setPosition(Vec2(1200, 80));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	layer->addChild(menu, 1);

	log("Edit It!");

	layer->scheduleUpdate();
}

void Test_Layer::testBtnCallback(Ref* pSender)
{
	auto light = AmbientLight::create(Color3B::RED);
	light->setIntensity(100.0f);
	layer->addChild(light);
	//�������ڲ��Կ�����
	//M_StepHandler::getInstance()->runStep(NULL,"None",NULL);
}
