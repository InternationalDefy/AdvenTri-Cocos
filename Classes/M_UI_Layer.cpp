#include "Ref2UI.h"

using namespace cocos2d;

bool UI_Layer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//一些初始属性的设置。
	_layerActionRunning = false; 
	_layerIsPaused = false; 
	_layerActionLimit = 0; 
	_layerActionScheduler = 0;

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(UI_Layer::menuCloseCallback, this));
	closeItem->setPosition(Vec2(0 + closeItem->getContentSize().width / 2,
		0 + closeItem->getContentSize().height / 2));
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	m = Sys_UI::getInstance()->getUIMenu("Test_Menu_1");
	m->setPosition(Vec2(640, 360));

	mk17 = Sys_UI::getInstance()->getDialogue("Test_Dialogue_1");
	mk17->retain();
	
	this->scheduleUpdate();
	return true;
}

Vec3 UI_Layer::getCameraPosition()
{
	auto s = getScene();
	auto c = s->getDefaultCamera();
	return c->getPosition3D();
}
void UI_Layer::instanceOpenMenu(UI_Menu* mu)
{
	this->addChild(mu,mu->getOnSetLocalZOrder());
	_openMenu.pushBack(mu);
	mu->enterMenu();
}
void UI_Layer::instanceQuitMenu(UI_Menu* mu)
{
	mu->quitMenu();
}
void UI_Layer::removeMenu(UI_Menu* mu)
{
	_openMenu.eraseObject(mu, false);
	mu->removeFromParentAndCleanup(false);
	mu->retain();
	mu->setVisible(false);
}
void UI_Layer::openMenu(const std::string& name)
{
	auto mu = _menuMap.at(name);
	if (mu)
	{
		openMenu(mu);
		return;
	}
	log("MenuUnfound!");
	return;
}
void UI_Layer::openMenu(UI_Menu* menu)
{
	if (menu->getState() != 0)
	{
		return;
	}
	if (_openMenu.contains(menu))
	{
		log("ThisMenuHas Opened!");
		return;
	}
	instanceOpenMenu(menu);
	return;
}
void UI_Layer::quitMenu(const std::string& name)
{
	auto mu = _menuMap.at(name);
	if (mu)
	{
		quitMenu(mu);
		return;
	}
	log("MenuUnfound!");
	return;
}
void UI_Layer::quitMenu(UI_Menu* menu)
{
	if (menu->getState() != 2)
	{
		return;
	}
	if (_openMenu.contains(menu))
	{
		instanceQuitMenu(menu);
		return;
	}
	log("This MenuHasnt Open");
	return;
}

void UI_Layer::instanceEnterDialogue(M_Dialogue* dia)
{
	this->addChild(dia, dia->getOnSetLocalZOrder());
	_openDialogue.pushBack(dia);
	dia->enterDialogue();
}
void UI_Layer::instanceQuitDialogue(M_Dialogue* dia)
{
	dia->quitDialogue();
}
void UI_Layer::removeDialogue(M_Dialogue* dia)
{
	_openDialogue.eraseObject(dia, false);
	dia->removeFromParentAndCleanup(false);
	dia->retain();
	dia->setVisible(false);
}
void UI_Layer::openDialogue(const std::string& name)
{
	auto dia = _dialogueMap.at(name);
	if (dia)
	{
		openDialogue(dia);
		return;
	}
	log("Dialogue UnFound!");
	return;
}
void UI_Layer::openDialogue(M_Dialogue* dia)
{
	if (dia->getState() != 0)
	{
		return;
	}
	if (_openDialogue.contains(dia))
	{
		log("ThisMenuHas Opened!");
		return;
	}
	instanceEnterDialogue(dia);
	return;
}
void UI_Layer::quitDialogue(const std::string& name)
{
	auto dia = _dialogueMap.at(name);
	if (dia)
	{
		quitDialogue(dia);
		return;
	}
	log("Dialogue Unfound!!");
	return;
}
void UI_Layer::quitDialogue(M_Dialogue* dia)
{
	if (dia->getState() != 2)
	{
		return;
	}
	if (_openDialogue.contains(dia))
	{
		instanceQuitDialogue(dia);
		return;
	}
	log("This Dialogue Hasnt Open");
	return;
}

Vec2 UI_Layer::convertUItoLayer(Vec2 ui)
{
	return Vec2(ui.x + getScene()->getDefaultCamera()->getPositionX(),
		ui.y + getScene()->getDefaultCamera()->getPositionY());
}
Vec2 UI_Layer::convertLayertoUI(Vec2 ly)
{
	return Vec2(ly.x - getScene()->getDefaultCamera()->getPositionX(),
		ly.y - getScene()->getDefaultCamera()->getPositionY());
}
void UI_Layer::updatePosition(float dt)
{
	float z = getPositionZ();
	if (getScene()->getDefaultCamera())
	{
		z = getCameraPosition().z - 622.0f;
		setPosition(Vec2(
			getCameraPosition().x - 640.0f,
			getCameraPosition().y - 360.0f));
	}
	setPositionZ(z);
}
void UI_Layer::update(float dt)
{
	updatePosition(dt);
	auto k = _children.size();
	if (k)
	{
		for (auto i = 0; i < k; ++i)
		{
			_children.at(i)->update(dt);
		}
	}
}

void UI_Layer::menuCloseCallback(Ref* pSender)
{
	//测试menu时使用
	/*
	if (_openMenu.contains(m))
	{
	quitMenu(m);
	return;
	}
	openMenu(m);
	*/
	//测试Dialogue时使用
	
	if (_openDialogue.contains(mk17))
	{
		quitDialogue(mk17);
	return;
	}
	openDialogue(mk17);
	
	return;
}