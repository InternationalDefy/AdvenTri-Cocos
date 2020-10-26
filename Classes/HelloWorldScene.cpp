#include "HelloWorldScene.h"
#include "Ref_Entity.h"
#include "DB_ebreed.h"
#include "Ref_Controller.h"
#include "Ref_Physics.h"
#include "Ref2EventSystem.h"
#include "DB_pSkill.h"
#include "Ctrl_Camera.h"
#include "M_player.h"
#include "Ref_Controller.h"
#include "Ref_Entity.h"
#include "Ref_EventSystem.h"
#include "Ref_LaEmoji.h"
#include "Ref_Item.h"
#include "Ref_Animation.h"
#include "Ref_UI.h"
#include "M_ScriptParser.h"
#include "Ref_SceneSystem.h"
#include "Ref_ActionHandler.h"
#include "Ref_Effect.h"
//不应该使用这个但在System建立起来之前暂时保留其。

//#include "Ref_Callback.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
	auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(TRUE);
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = HelloWorld::create();
	scene->addChild(layer);
	/*
	auto uil = UI_Layer::create();
	scene->addChild(uil,1);
	uil->setEntityLayer(layer);
	*/
	return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
  
	pc = DB_PlayerController::getInstance()
		->getPlayerControllerSD("pctrl_speed_1")->createPctrlFromSD();

	t = M_Player::create("triangle_full_hp.png");
	t->setPosition(Vec2(640, 360));
	addChild(t, 1);
	t->setPhysicsBody(DB_Physics::getInstance()->getBody("boot"));
	t->setController(pc);
	t->activepCtrl();
	DB_pSkill::getInstance()->addSkillToPlayer("attack_lv1", t);
	DB_pSkill::getInstance()->addSkillToPlayer("attack_lv2", t);
	DB_pSkill::getInstance()->addSkillToPlayer("speak1", t);
	DB_pSkill::getInstance()->addSkillToPlayer("dash_simple_lv1", t);
	DB_pSkill::getInstance()->addSkillToPlayer("dash_attack_lv1", t);
	
	//t->addAnimationPack(DB_AnimationPack::getInstance()->getAnimationPack("TriAngle_Animation_Pack"));

	bg = Sprite::create("b1.jpg");
	bg->setPosition(Vec2(visibleSize.width*0.5, visibleSize.height*0.5));
	bg->setPositionZ(0);
	//bg->setColor(Color3B(0, 0, 255));
	this->addChild(bg, -20);

	auto bg1 = Sprite::create("b2.jpg");
	bg1->setPosition(Vec2(visibleSize.width*0.5, visibleSize.height*0.5));
	bg1->setPositionZ(-622);
	//bg1->setColor(Color3B(255, 0, 0));
	this->addChild(bg1, -30);

	cc = NULL;
	/*
	e = DB_EBreed::getInstance()->createEnemy("namea");
	this->addChild(e, 1);
	e->assignEventListener();
	e->activeController();
	e->setPosition(Vec2(960, 360));
	*/
	sys = Sys_Event::getInstance();
	sys->addPhysicsListenerToNode(this);
	
	auto dban = DB_Animate::getInstance();
	auto dbanim = DB_Animation::getInstance();
	auto dbanip = DB_AnimationPack::getInstance();
	M_ActionHandler::getInstance()->addAnimationPackToEntity(t, "PackageA");
	M_ActionHandler::getInstance()->addAnimationPackToEntity(t, "PackageB");
	
	/*
	auto sd = DB_GameLayer::getInstance()->getGameLayerSD("Test_GameLayer_2");
	auto sce = Sys_Scene::getInstance()->getGameScene(sd);

	//auto dspt = DB_SplashLayer::getInstance();
	//auto dp = DB_Scene::getInstance();
	//以下，留作一种标准的脚本使用模式。
	/*
	auto pas = M_ScriptParser::getInstance();
	Vector<String*> sct;
	sct.pushBack(String::create("INT"));
	sct.pushBack(String::create("28"));
	sct.pushBack(String::create("INT"));
	sct.pushBack(String::create("19"));
	sct.pushBack(String::create(">"));
	sct.pushBack(String::create("RET_BOOL"));
	sct.pushBack(String::create("Nope!"));
	bool is=pas->handleJudgeScript(&sct);
	
	sct.clear();

	sct.pushBack(String::create("FLOAT"));
	sct.pushBack(String::create("17"));
	sct.pushBack(String::create("FLOAT"));
	sct.pushBack(String::create("19"));
	sct.pushBack(String::create(">"));
	sct.pushBack(String::create("RET_BOOL"));
	sct.pushBack(String::create("Nope!"));
	is = pas->handleJudgeScript(&sct);
	*/
	this->scheduleUpdate();
	return true;
}

void HelloWorld::update(float dt)
{
	auto k = _children.size();
	for (auto i = 0; i < k;++i)
	{
		_children.at(i)->update(dt);
	}
	if (!cc)
	{
		cc = Ctrl_Camera::create(dynamic_cast<Scene*> (getParent()));
		//cc->moveCameraZ(1.0f, 311);
		cc->setBorderLimited(0, 0, 0, 0);
		cc->setPlayerController(pc);
		pc->setCameraController(cc);

		this->addChild(cc);
	}
	else
	{
		//cc->moveCameraZ(1.0f, 311);
	}

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	/*
	auto k = pack->getLaEmoji("key1");
	k->setPosition(Vec2(1280 * CCRANDOM_0_1(), 720 * CCRANDOM_0_1()));
	k->addToScene(this, 10);
	k->activeLaEmoji();
	*/
	/*
	if (!f)
	{
		t->setHurtDamage(1);
		t->setHurtType(AdvenTriEnum::DamageType::D_TYPE_ICY);
		t->setDebuffLimit(5.0f);
		t->doHurt();
		f = true;
	}
	else
	{
		t->setHurtDamage(1);
		t->setHurtType(AdvenTriEnum::DamageType::D_TYPE_BURN);
		t->setDebuffLimit(5.0f);
		t->doHurt();
		f = false;
	}
	*/
	/*
	M_ActionHandler::getInstance()->runEnvirAction(this, 
		Vec3(CCRANDOM_0_1() * 1280, CCRANDOM_0_1() * 720, 0), 2, "AnimationD");
	t->runAnimation("key1");
	*/
	
	t->setShadow(420.0f, 256.0f); 
}