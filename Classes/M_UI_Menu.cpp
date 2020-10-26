#include "Ref2UIMenu.h"

bool UI_Menu::init()
{
	_numItems = 0;
	_state = 0;
	_enterAction = NULL;
	_quitAction = NULL;
	_visible = FALSE;
	_onSetLocalZOrder = 0;
	_enterInstance = FALSE;
	setCascadeOpacityEnabled(TRUE);
	setOpacity(0);
	return TRUE;
}
void UI_Menu::addItem(UI_Item* item)
{
	itemAddInstance(item, 0, FALSE);
	return;
}
void UI_Menu::addItem(UI_Item* item, int tag)
{
	itemAddInstance(item, tag, TRUE);
	return;
}
void UI_Menu::itemAddInstance(UI_Item* item, int tag,bool usTag)
{
	_itemVector.pushBack(item);
	_numItems += 1;
	addChild(item);
	if (!usTag)
	{
		return;
	}
	_itemMap.insert(tag, item);
	return;
}
/*
Vec2 UI_Menu::convertVec2ToLayerPosition(Vec2 vec2)
{
	return Vec2(0, 0);
}
Vec2 UI_Menu::convertVec2ToUiPosition(Vec2 vec2)
{
	return Vec2(0, 0);
}
*/
/*
void UI_Menu::initWithCamera(Ctrl_Camera* cctrl)
{
	setCameraInstance(cctrl);
	return;
}
void UI_Menu::setCameraInstance(Ctrl_Camera* cctrl)
{
	_cctrl = cctrl;
	_Z = cctrl->getCameraHeight();
	_Z -= 622.0f;
	return;
}
*/
void UI_Menu::enterMenu()
{
	_state = 1;
	setVisible(TRUE);
	runAction(Sequence::create(_enterAction,
		CallFunc::create(std::bind(&UI_Menu::enterItems, this)),
		CallFunc::create([&](){
			this->_state = 2; 
		}),
		NULL));
	//VecIntoSys ?in SYs?
}
void UI_Menu::enterItems()
{
	auto k = _itemVector.size();
	for (auto i = 0; i < k; ++i)
	{
		_itemVector.at(i)->setVisible(TRUE);
		_itemVector.at(i)->enterItem();
	}
}
void UI_Menu::quitMenu()
{
	this->_state = 3;
	runAction(Sequence::create(Spawn::createWithTwoActions(_quitAction,
		CallFunc::create(std::bind(&UI_Menu::quitItems, this))),
		CallFunc::create(std::bind(&UI_Layer::removeMenu,dynamic_cast<UI_Layer*>(getParent()),this)),
		CallFunc::create([&](){
			this->_state = 0; 
		}),
		NULL));
	//maybe some clean up in Sys_UI;
}
void UI_Menu::quitItems()
{
	auto k = _itemVector.size();
	for (auto i = 0; i < k; ++i)
	{
		_itemVector.at(i)->quitItem();
	}
}

void UI_Menu::update(float dt)
{
	/*
	if (_cctrl)
	{
		_Z = _cctrl->getCameraHeight() - 622.0f;
		setPosition(Vec2(
			_cctrl->getCameraPosition2D().x+_offCameraVec2.x,
			_cctrl->getCameraPosition2D().y+_offCameraVec2.y));
	}
	setPositionZ(_Z);
	*/
	auto k = _children.size();
	if (k)
	{
		for (int i = 0; i < k; ++i)
		{
			_children.at(i)->update(dt);
		}
	}
	return;
}
