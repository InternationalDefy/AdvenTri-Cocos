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
	//这里也许不用重新创建UI层，而是改换？或者GetInstance？
	//亟待考量。
	auto uil = UI_Layer::create();
	scene->addChild(uil, 1);
	uil->setEntityLayer(layer);
	return scene;
}
/*
测试体系完成！
在该edit方法中修改需要测试的内容。
*/
void Test_Layer::editTestLayer(M_GameLayer* layer)
{
	/*
	以下为LaEmoji测试。
	M_LaEmoji* la = Sys_LaEmoji::getInstance()->getLaEmoji("Test_LaEmoji_1");
	la->setPosition(Vec2(640, 360));
	layer->addChild(la, 1);
	la->enter();
	*/
	
	layer->tFuncAddEnemy("TestEnemy", Vec3(960, 360, 0), 1, "enemy1");

	//以下语句很不规范，仅在小测试中使用。
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
	//以下是在测试控制器
	//M_StepHandler::getInstance()->runStep(NULL,"None",NULL);
}
