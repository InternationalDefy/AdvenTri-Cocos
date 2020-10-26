#include "Ref2Dialogue.h"
#include "M_UI_Layer.h"

using namespace cocos2d;

bool Page_Dialogue::init()
{
	_dialogue = NULL;
	_enterAction = NULL;
	_quitAction = NULL;
	_actived = FALSE;
	_laEmoji = NULL;
	return TRUE;
}

/*
以下我们要做一些体力活。。。
直到下一个注释语句到来之前。
*/
void Page_Dialogue::pushItem(UI_Item* item)
{
	if (!item)
	{
		log("Stop!");
		return;
	}
	addChild(item, 2);
	_diaCtrlitem.pushBack(item);
	return;
}
void Page_Dialogue::enterPage()
{
	setVisible(TRUE);
	runAction(Sequence::create(_enterAction,
		CallFunc::create(std::bind(&Page_Dialogue::enterItem, this)),
		NULL));
}
void Page_Dialogue::quitPage()
{
	runAction(Sequence::create(Spawn::createWithTwoActions(_quitAction,
		CallFunc::create(std::bind(&Page_Dialogue::quitItem, this))),
		CallFunc::create([&](){
		this->setVisible(FALSE);
	}),
		NULL));
}
void Page_Dialogue::enterItem()
{
	auto k = _diaCtrlitem.size();
	_laCtrlItemLastPage->setVisible(TRUE);
	_laCtrlItemLastPage->enterItem();
	_laCtrlItemNextPage->setVisible(TRUE);
	_laCtrlItemNextPage->enterItem();
	for (auto i = 0; i < k; ++i)
	{
		_diaCtrlitem.at(i)->setVisible(TRUE);
		_diaCtrlitem.at(i)->enterItem();
	}
}
void Page_Dialogue::quitItem()
{
	auto k = _diaCtrlitem.size();
	_laCtrlItemLastPage->quitItem();
	_laCtrlItemNextPage->quitItem();
	for (auto i = 0; i < k; ++i)
	{
		_diaCtrlitem.at(i)->quitItem();
	}
}

void Page_Dialogue::setEnterAction(FiniteTimeAction* act)
{
	if (!act)
	{
		log("Stop!");
		return;
	}
	_enterAction = act;
	_enterAction->retain();
	return;
}
void Page_Dialogue::setQuitAction(FiniteTimeAction* act)
{
	if (!act)
	{
		log("Stop!");
		return;
	}
	_quitAction = act;
	_quitAction->retain();
	return;
}
void Page_Dialogue::setLaEmoji(M_LaEmoji* act){
	if (!act)
	{
		log("Stop!");
		return;
	}
	addChild(act, 1);
	_laEmoji = act;
	return;
}
void Page_Dialogue::setNextPageLaCtrlItem(UI_Item* act){
	if (!act)
	{
		log("Stop!");
		return;
	}
	addChild(act, 2);
	_laCtrlItemNextPage = act;
	return;
}
void Page_Dialogue::setLastPageLaCtrlItem(UI_Item* act){
	if (!act)
	{
		log("Stop!");
		return;
	}
	addChild(act, 2);
	_laCtrlItemLastPage = act;
	return;
}
void Page_Dialogue::setBackGround(Sprite* sp)
{
	if (sp)
	{
		addChild(sp, 0);
		_backGround = sp;
		return;
	}
	log("Stop!");
	return;
}
void Page_Dialogue::setCharIcon(Sprite* sp)
{
	if (sp)
	{
		addChild(sp, 2);
		_charIcon = sp;
		return;
	}
	log("Stop!");
	return;
}
void Page_Dialogue::setDialogue(M_Dialogue* act)
{
	if (!act)
	{
		log("Stop!");
		return;
	}
	_dialogue = act;
	return;
}
M_Dialogue* Page_Dialogue::getDialogue()
{
	if (_dialogue)
		return _dialogue;
	log("Fuck Ya R U Kiddding me!?");
}
void Page_Dialogue::update(float dt)
{
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
/*
------------------------------------------------------------------------------
==================总觉得，得有点什么东西把两个类的实现分开啊==================
------------------------------------------------------------------------------
*/
bool M_Dialogue::init()
{
	_currentPage = NULL;
	_onSetLocalZOrder = 3;
	_state = 0;
	_actived = FALSE;
	_enterAction = NULL;
	_quitAction = NULL;
	_visible = FALSE;
	setOpacity(0);
	return TRUE;
}
/*
下面这两个函数是从上面直接粘贴过来的！
*/
void M_Dialogue::setEnterAction(FiniteTimeAction* act)
{
	if (!act)
	{
		log("Stop!");
		return;
	}
	_enterAction = act;
	_enterAction->retain();
	return;
}
void M_Dialogue::setQuitAction(FiniteTimeAction* act)
{
	if (!act)
	{
		log("Stop!");
		return;
	}
	_quitAction = act;
	_quitAction->retain();
	return;
}
void M_Dialogue::pushPage(Page_Dialogue* page)
{
	if (!page)
	{
		log("Stop!");
		return;
	}
	addChild(page, 3);
	_page.pushBack(page);
	return;
}
void M_Dialogue::enterDialogue()
{
	_state = 1;
	setVisible(TRUE);
	runAction(Sequence::create(_enterAction,
		CallFunc::create(std::bind(&M_Dialogue::nextPage, this, 0)),
		CallFunc::create([&](){
		this->_state = 2;
	}),
		NULL));
}
void M_Dialogue::quitDialogue()
{
	this->_state = 3;
	runAction(Sequence::create(Spawn::createWithTwoActions(_quitAction,
		CallFunc::create(std::bind(&Page_Dialogue::quitPage, _currentPage))),
		CallFunc::create(std::bind(&UI_Layer::removeDialogue, dynamic_cast<UI_Layer*>(getLayer()), this)),
		CallFunc::create([&](){
		this->_state = 0;
		this->_currentPage = NULL;
	}),
		NULL));
}
void M_Dialogue::nextPage(int index)
{
	auto mp = _page.at(index);
	if (!mp)
	{
		log("Stop");
		return;
	}
	if (mp == _currentPage)
	{
		return;
	}
	if (_currentPage)
	{
		runAction(Sequence::create(
			CallFunc::create(std::bind(&Page_Dialogue::quitPage, _currentPage)),
			CallFunc::create(std::bind(&Page_Dialogue::enterPage,mp)),
			NULL));
		return;
	}
	mp->setVisible(TRUE);
	_currentPage = mp;
	mp->enterPage();
	return;
}
void M_Dialogue::update(float dt)
{
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