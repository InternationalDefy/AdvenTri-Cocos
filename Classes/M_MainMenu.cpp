#include "Ref2SceneSystem.h"
#include "Ref_Controller.h"

#define MAINMENU_RAND_ENTITY 3
#define MAINMENU_SHADOW_HEIGHT 622.0f
#define MAINMENU_SHADOW_DEPTH 62.0f
#define MAINMENU_CASCUDE_COLOR Color3B(245,245,205)

using namespace cocos2d;

/*
在游戏开始时加载所有的数据库。
*/
void M_MainMenu::initAllDataBase()
{
	/*
	DB_Amor::getInstance();
	DB_Animate::getInstance();
	DB_Animation::getInstance();
	DB_AnimationPack::getInstance();
	DB_Dialog::getInstance();
	DB_Dialogue::getInstance();
	DB_EBreed::getInstance();
	DB_Emoji::getInstance();
	DB_GameLayer::getInstance();
	DB_Npc::getInstance();
	DB_Physics::getInstance();
	DB_Unit::getInstance();
	DB_Weapon::getInstance();
	Sys_Item::getInstance();
	Sys_Ctrl::getInstance();
	Sys_LaEmoji::getInstance();
	Sys_Event::getInstance();
	Sys_Save::getInstance();
	Sys_Scene::getInstance();
	Sys_UI::getInstance();
	*/
}

bool M_MainMenu::init()
{
	if (!Layer::init())
	{
		return FALSE;
	}
	auto k = DB_Ctrl::getInstance();
	initPhysicsMenu();
	scheduleUpdate();
	return TRUE;
}

void M_MainMenu::initPhysicsMenu()
{
	Sprite* pencil = Sprite::create();
	pencil->runAction(DB_Animate::getInstance()->getAnimate("MainMenuPencil"));
	float rotation = 77.0f;
	float moverange = 400.0f;
	float bytime = 5.0f;
	float anger = (90.0f - rotation) * 3.14f / 180.0f;
	/*
	Vec2 byVec2 = Vec2(moverange * cos(anger), moverange * sin(anger));
	Vec2 b2Vec2 = -byVec2;
	pencil->runAction(RepeatForever::create(Sequence::create(
		MoveBy::create(bytime, byVec2),
		MoveBy::create(bytime, b2Vec2),
		NULL)));
	*/
	Vec2 byVec2 = -Vec2(1900 * cos(anger), 1900 * sin(anger));
	pencil->runAction(RepeatForever::create(
		Sequence::create(MoveBy::create(19.0f, byVec2),
		MoveTo::create(0.0f, Vec2(700 * cos(anger) + 890, 700 * sin(anger) + 320)),
		NULL)));

	pencil->setScale(0.14f);
	pencil->setRotation(rotation);
	pencil->setPosition(Vec2(700 * cos(anger) + 890, 700 * sin(anger) + 320));
	addChild(pencil, 10);

	Sprite* bg = Sprite::create("MainMenuBackGround.png");
	addChild(bg, 0);
	bg->setPosition(Vec2(640,360));
	
	bg->setPhysicsBody(DB_Physics::getInstance()->getBody("MainMenuBody"));
	

	float x = CCRANDOM_0_1()*MAINMENU_RAND_ENTITY+2;
	float y = CCRANDOM_0_1()*MAINMENU_RAND_ENTITY+2;
	float z = CCRANDOM_0_1()*MAINMENU_RAND_ENTITY+2;
	
	for (auto i = 0; i < x; ++i)
	{
		addRect();
	}
	for (auto i = 0; i < y; ++i)
	{
		addTriangle();
	}
	for (auto i = 0; i < z;++i)
	{
		addCircle();
	}
	
}

void M_MainMenu::addRect()
{
	PhysicsBody* bd = PhysicsBody::createBox(Size(108, 108));
	Entity* sp = Entity::create("MainMenuRectAngle.png");
	sp->setShadow(MAINMENU_SHADOW_HEIGHT, MAINMENU_SHADOW_DEPTH);
	sp->setPhysicsBody(bd);
	sp->setPosition(Vec2(100 + CCRANDOM_0_1() * 1080, 20 + CCRANDOM_0_1() * 680));
	sp->setScale((CCRANDOM_0_1()*0.4f + 0.60f));
	sp->setColor(MAINMENU_CASCUDE_COLOR);
	_rect.push_back(sp);
	sp->retain();
	sp->setController(Sys_Ctrl::getInstance()->getControllerWithName("3"));
	sp->activeController();
	this->addChild(sp, 1);
}
void M_MainMenu::addTriangle()
{
	Vec2 points[] = { Vec2(-28, 50), Vec2(58, 0), Vec2(-28, -50) };
	PhysicsBody* bd = PhysicsBody::createPolygon(points,3);
	Entity* sp = Entity::create("MainMenuTriAngle.png");
	sp->setShadow(MAINMENU_SHADOW_HEIGHT, MAINMENU_SHADOW_DEPTH);
	sp->setPhysicsBody(bd);
	sp->setPosition(Vec2(100 + CCRANDOM_0_1() * 1080, 20 + CCRANDOM_0_1() * 680));
	sp->setScale((CCRANDOM_0_1()*0.4f + 0.60f));
	sp->setColor(MAINMENU_CASCUDE_COLOR);
	sp->retain();
	sp->setController(Sys_Ctrl::getInstance()->getControllerWithName("3"));
	/*
	sp->setController(Ctrl_MenuRandom::create(
		0.7f + 0.6f*CCRANDOM_0_1(), 0.7f + 0.6f*CCRANDOM_0_1(), 150.0f + 100 * CCRANDOM_0_1()));
	*/
	sp->activeController();
	_triangle.push_back(sp);
	this->addChild(sp, 1);
}
void M_MainMenu::addCircle()
{
	PhysicsBody* bd = PhysicsBody::createCircle(54);
	Entity* sp = Entity::create("MainMenuCircle.png");
	sp->setShadow(MAINMENU_SHADOW_HEIGHT, MAINMENU_SHADOW_DEPTH);
	sp->setPhysicsBody(bd);
	sp->setPosition(Vec2(100 + CCRANDOM_0_1() * 1080, 20 + CCRANDOM_0_1() * 680));
	sp->setScale((CCRANDOM_0_1()*0.4f + 0.60f));
	sp->setColor(MAINMENU_CASCUDE_COLOR);
	_circle.push_back(sp);
	sp->setController(Sys_Ctrl::getInstance()->getControllerWithName("3"));
	sp->activeController();
	sp->retain();
	this->addChild(sp, 1);
}

void M_MainMenu::update(float dt)
{
	int k = _children.size();
	for (auto i = 0; i < k; ++i)
	{
		_children.at(i)->update(dt);
	}
}

Scene* M_MainMenu::createScene()
{
	auto scene = Scene::createWithPhysics();

	//scene->getPhysicsWorld()->setDebugDrawMask(TRUE);

	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = M_MainMenu::create();
	scene->addChild(layer);
		
	return scene;
}