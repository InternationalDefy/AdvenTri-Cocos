#include "Ref2SceneSystem.h"
#include "Ref_Entity.h"
#include "Ref_TestCase.h"
#include "Ref_UI.h"

M_GameLayer* M_GameLayer::create(SD_GameLayer* sd)
{
	M_GameLayer* pRet = new (std::nothrow) M_GameLayer();
	if (pRet&&pRet->init(sd))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
bool M_GameLayer::init(SD_GameLayer* sd)
{
	if (!Layer::init())
	{
		return FALSE;
	}
	if (!initBorder(sd))
		log("Border Init Failed!");
	if (!initNpc(sd))
		log("Npc Init Failed!");
	if (!initEnemy(sd))
		log("Enemy Init Failed!");
	if (!initPlayer())
		log("Player Init Failed!");
	if (!initBackground(sd))
		log("BG Init Failed!");
	if (!initPhysicsEvent(sd))
		log("Physcis Init Failed!");
	if (!initEventDispatcher(sd))
		log("Event Init Failed!");
	return true;
}
Scene* M_GameLayer::getScene(SD_GameLayer* sd)
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
	auto layer = M_GameLayer::create(sd);
	scene->addChild(layer);
	//这里也许不用重新创建UI层，而是改换？或者GetInstance？
	//亟待考量。
	auto uil = UI_Layer::create();
	scene->addChild(uil, 1);
	uil->setEntityLayer(layer);
	return scene;
}
bool M_GameLayer::initBorder(SD_GameLayer* sd)
{
	PhysicsBody* body = PhysicsBody::create();
	for (auto i = 0; i < sd->getBorderItems()->size(); ++i)
	{
		PhysicsShapeBox* shape = PhysicsShapeBox::create(
			Size(sd->getBorderItems()->at(i).width,sd->getBorderItems()->at(i).height),
			PhysicsMaterial::PhysicsMaterial(0,0,0),sd->getBorderItems()->at(i).position);
		body->addShape(shape);
	}
	physicsBorder = Node::create();
	physicsBorder->setPhysicsBody(body);
	physicsBorder->setPosition(Vec2::ZERO);
	this->addChild(physicsBorder);
	return true;
}
bool M_GameLayer::initNpc(SD_GameLayer* sd)
{
	for (auto i = 0; i < sd->getNumberOfNpc(); ++i)
	{
		if (M_ScriptParser::getInstance()->handleJudgeScript(&sd->getNpcItems()->at(i).scripts))
		{
			M_Npc* npc = M_Npc::create(sd->getNpcItems()->at(i).itemName);
			npc->setPosition3D(sd->getNpcItems()->at(i).position3D);
			npc->EntityTAG = sd->getNpcItems()->at(i).itemTag;
			npc->EntityState = Sys_Save::getInstance()->getSceneSave(GameLayerTag, sd->getNpcItems()->at(i).itemTag);
			EntityState.insert(std::make_pair(npc->EntityTAG, npc->EntityState));
			this->addChild(npc, sd->getNpcItems()->at(i).localZOrder);
		}
	}
	return true;
}
bool M_GameLayer::initEnemy(SD_GameLayer* sd)
{
	for (auto i = 0; i < sd->getNumberOfEnemy(); ++i)
	{
		if (M_ScriptParser::getInstance()->handleJudgeScript(&sd->getEnemyItems()->at(i).scripts))
		{
			M_Enemy* enemy = M_Enemy::create(sd->getEnemyItems()->at(i).itemName);
			enemy->setPosition3D(sd->getEnemyItems()->at(i).position3D);
			enemy->EntityTAG = sd->getEnemyItems()->at(i).itemTag;
			enemy->EntityState = Sys_Save::getInstance()->getSceneSave(GameLayerTag, sd->getEnemyItems()->at(i).itemTag);
			EntityState.insert(std::make_pair(enemy->EntityTAG, enemy->EntityState));
			this->addChild(enemy, sd->getEnemyItems()->at(i).localZOrder);
		}
	}
	return true;
}
bool M_GameLayer::initPlayer()
{
	
	return true;
}
bool M_GameLayer::initBackground(SD_GameLayer* sd)
{
	for (auto i = 0; i < sd->getNumberOfBackGround(); ++i)
	{
		Sprite* sp = Sprite::create(sd->getBackGroundItems()->at(i).image);
		sp->setPosition3D(sd->getBackGroundItems()->at(i).position3D);
		if (sd->getBackGroundItems()->at(i).enableListener)
			Sys_Event::getInstance()->addListenerSetTo(sp, sd->getBackGroundItems()->at(i).listenerSetName);
		if (sd->getBackGroundItems()->at(i).enableAction)
			sp->runAction(Repeat::create(M_ActionHandler::getInstance()->getAction(sp, 
			sd->getBackGroundItems()->at(i).actionType,
			&sd->getBackGroundItems()->at(i).actionParams), -1));
		addChild(sp, sd->getBackGroundItems()->at(i).localZOrder);
	}
	return true;
}
bool M_GameLayer::initPhysicsEvent(SD_GameLayer* sd)
{
	Sys_Event::getInstance()->addPhysicsListenerToNode(this);
	return true;
}
bool M_GameLayer::initEventDispatcher(SD_GameLayer* sd)
{
	Sys_Event::getInstance()->addListenerSetTo(this, sd->getListenerSetName());
	return true;
}
M_GameLayer::M_GameLayer()
{
	_isPaused = FALSE;
	uiLayer = NULL;
	cameraCtrl = NULL;
	playerCtrl = NULL;
	cameraBorder = NULL;
	physicsBorder = NULL;
	player = NULL;
	GameLayerTag = "";
}
void M_GameLayer::update(float dt)
{
	int k = _children.size();
	for (int i = 0; i < k; ++i)
	{
		_children.at(i)->update(dt);
	}
	if (!cameraCtrl&&playerCtrl)
	{
		cameraCtrl = Ctrl_Camera::create(dynamic_cast<Scene*> (getParent()));
		//cc->moveCameraZ(1.0f, 311);
		cameraCtrl->setBorderLimited(0, 0, 0, 0);
		cameraCtrl->setPlayerController(playerCtrl);
		playerCtrl->setCameraController(cameraCtrl);

		this->addChild(cameraCtrl);
	}
}

//以下方法仅在测试体系中使用。
M_GameLayer* M_GameLayer::create()
{
	M_GameLayer* pRet = new (std::nothrow) M_GameLayer();
	if (pRet)
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}

void M_GameLayer::tFuncAddEnemy(const std::string& name, Vec3 pos3, int localZOrder,const std::string& Tag)
{
	M_Enemy* enemy = DB_EBreed::getInstance()->createEnemy(name);
	enemy->setPosition3D(pos3);
	enemy->EntityTAG = Tag;
	EntityState.insert(std::make_pair(Tag, 1));
	this->addChild(enemy, localZOrder,Tag);
}
void M_GameLayer::tFuncAddNpc(const std::string& name, Vec3 pos, int localZOrder,const std::string& Tag)
{
	M_Npc* npc = M_Npc::create(name);
	npc->setPosition3D(pos);
	npc->EntityTAG = Tag;
	EntityState.insert(std::make_pair(Tag, 1));
	this->addChild(npc, localZOrder,Tag);
}
void M_GameLayer::tFuncAddPlayer(int localZOrder,const std::string& sznPlayerCtrl,const std::string& sznPlayerPhysicsBody)
{
	player = M_Player::create("triangle_full_hp.png");
	player->setPosition(Vec2(640, 360));
	playerCtrl = DB_PlayerController::getInstance()
		->getPlayerControllerSD(sznPlayerCtrl)->createPctrlFromSD();
	player->setPhysicsBody(DB_Physics::getInstance()->getBody(sznPlayerPhysicsBody));
	player->setController(playerCtrl);
	addChild(player, localZOrder);
	player->activepCtrl();
}
M_Player* M_GameLayer::tFuncGetPlayer()
{
	return player;
}
void M_GameLayer::tFuncSetBorder(const std::string& snBorderFile)
{
	FILE* pFile;
	fopen_s(&pFile, snBorderFile.c_str(), "r");
	
	int bor[256];
	int i = 0;
	/*bor[x] x:
	0,4,8,... posx
	1,5,9,... posy
	2,6,10,.. width
	3,7,11,.. height
	*/
	int tmp = fgetwc(pFile); 
	while (tmp != EOF) 
	{
		bor[i] = tmp;
		i++;
		tmp = fgetwc(pFile);
	} 
	
	fclose(pFile);

	PhysicsBody* body = PhysicsBody::create();
	for (auto j = 0; j < ((i + 1) / 4); ++j)
	{
		PhysicsShapeBox* shape = PhysicsShapeBox::create(
			Size(bor[j * 4 + 2], bor[j * 4 + 3]),
			PhysicsMaterial::PhysicsMaterial(0, 0, 0),
			Vec2(bor[4 * j], bor[4 * j + 1]));
		body->addShape(shape);
	}
	physicsBorder = Node::create();
	physicsBorder->setPhysicsBody(body);
	physicsBorder->setPosition(Vec2::ZERO);
	this->addChild(physicsBorder);
	
	delete bor;
}
void M_GameLayer::tFuncSetBackground(const std::string& sdnBackground)
{
	SD_GameLayer* sd = DB_GameLayer::getInstance()->getGameLayerSD(sdnBackground);

	for (auto i = 0; i < sd->getNumberOfBackGround(); ++i)
	{
		Sprite* sp = Sprite::create(sd->getBackGroundItems()->at(i).image);
		sp->setPosition3D(sd->getBackGroundItems()->at(i).position3D);
		if (sd->getBackGroundItems()->at(i).enableListener)
			Sys_Event::getInstance()->addListenerSetTo(sp, sd->getBackGroundItems()->at(i).listenerSetName);
		if (sd->getBackGroundItems()->at(i).enableAction)
			sp->runAction(Repeat::create(M_ActionHandler::getInstance()->getAction(sp,
			sd->getBackGroundItems()->at(i).actionType,
			&sd->getBackGroundItems()->at(i).actionParams), -1));
		addChild(sp, sd->getBackGroundItems()->at(i).localZOrder);
	}
}
void M_GameLayer::tFuncInitPhysicsEvent()
{
	Sys_Event::getInstance()->addPhysicsListenerToNode(this);
}
void M_GameLayer::tFuncInitEventDispatcher(const std::string& snListenerSet)
{
	Sys_Event::getInstance()->addListenerSetTo(this, snListenerSet);
}