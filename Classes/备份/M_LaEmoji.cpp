/*
#include "M_LaEmoji.h"
#include "M_Emoji.h"
#include "M_Dialog.h"
*/
#include "Ref2LaEmoji.h"

USING_NS_CC;

M_LaEmoji* M_LaEmoji::create(SD_LaEmoji* laEmojiList,Layer* layer)
{
	M_LaEmoji *piece = new (std::nothrow) M_LaEmoji();
	if (piece)
	{
		piece->init(laEmojiList, layer);
		piece->autorelease();
		return piece;
	}
	CC_SAFE_DELETE(piece);
	return nullptr;
}

/**
设计思路
按顺序排列M_Emoji，过了Size.x换行，
按顺序排列M_Emoji，过了Size.y换页，
*/
void M_LaEmoji::init(SD_LaEmoji* laEmojiList, Layer* layer)
{
	/*
	dialogSize = dialog->getContentSize();
	emojiNum = emojis->size();
	x = 0;
	int blockNum = 0;
	y = 0;
	pageNow = 0;
	pages.pushBack(M_PageEmoji::create());
	for (int i = 0; i < emojiNum; ++i)
	{
		if (blockNum==0)
		emojis->at(i)->setPosition(Vec2(
			-0.5*dialog->getAdjustSize().x+dialog->getBorder()+emojis->at(i)->getContentSize().width*0.5,
			0.5*dialog->getAdjustSize().y-dialog->getBorder()-emojis->at(i)->getContentSize().height*0.5));
		pages.at(pageNow)->push(emojis->at(i));
		//x += emojis->at(i)->getRealSizeX(); 
		if (x > dialogSize.x)
		{
			y += 1;
		}
	}
	1*/
	//基础初始化
	_parentLayer = layer;
	_activitedPage = 0;

	_tempEmojis.clear();

	for (int i = 0; i < laEmojiList->getSdEmojis()->size(); ++i)
	{
		auto sd = laEmojiList->getSdEmojis()->at(i);
		auto k = M_Emoji::createWithEmojiData(sd);
		_tempEmojis.pushBack(k);
	}
	M_Dialog* dialog = M_Dialog::createWithDialogData(laEmojiList->getDialog());
	_animationType = laEmojiList->getAnimationType();
	int pageNow = 1;
	int heightGuess = 0;
	int widthGuess = 0;
	int emojiNum = _tempEmojis.size();
	int width = dialog->getAdjustSize().x - dialog->getBorder() * 2;
	int height = dialog->getAdjustSize().y - dialog->getBorder() * 2;
	std::vector<int> lineMaxBlocks;
	std::vector<int> lineMaxHeight; 
	//每页初始化
	lineMaxBlocks.clear();
	lineMaxHeight.clear();
	int heightNow = 0;
	int lineNow = 0;
	pageNow += 1;
	//每行初始化
	int blockNow = 0;
	int widthNow = 0;
	lineMaxHeight.push_back(0);

	M_PageEmoji* pageOfPiece = M_PageEmoji::create();

	for (int i = 0; i < emojiNum; ++i)
	{
		blockNow += 1;
		int tempInt = MAX(lineMaxHeight.at(lineNow), _tempEmojis.at(i)->getSize().y);
		lineMaxHeight.pop_back();
		lineMaxHeight.push_back(tempInt);
		
		widthGuess = widthNow + _tempEmojis.at(i)->getSize().x;

		if (widthGuess > width)
		{
			heightGuess = heightNow + _tempEmojis.at(i)->getSize().y + lineMaxHeight.at(lineNow);
			if (heightGuess > height)
			{
				//换页前应该先创建保存当前Page
				_pages.pushBack(pageOfPiece);
				addChild(pageOfPiece);
				pageOfPiece = M_PageEmoji::create();
				//换页
				lineMaxBlocks.clear();
				lineMaxHeight.clear();
				heightNow = 0;
				lineNow = 0;
				pageNow += 1;
				//每行初始化
				blockNow = 0;
				widthNow = 0;
				lineMaxHeight.push_back(0);
			}
			else
			{
				//换行
				lineMaxBlocks.push_back(blockNow);
				heightNow += lineMaxHeight.at(lineNow);
				lineNow += 1;
				widthNow = 0;
				blockNow = 0;
				lineMaxHeight.push_back(0);
			}
		}
		/* 调试时使用
		int k = i;
		Vec2 pos = Vec2(Vec2(
			-width*0.5 + widthNow + emojis->at(i)->getSize().x*0.5,
			height*0.5 - heightNow - emojis->at(i)->getSize().y*0.5));
		*/
		_tempEmojis.at(i)->setPosition(Vec2(
			-width*0.5 + widthNow + _tempEmojis.at(i)->getSize().x*0.5,
			height*0.5 - heightNow - _tempEmojis.at(i)->getSize().y*0.5));
		widthNow += _tempEmojis.at(i)->getSize().x;
		pageOfPiece->push(_tempEmojis.at(i));
	}
	_pages.pushBack(pageOfPiece);
	_thisDialog = dialog;

	addChild(pageOfPiece);
	addChild(dialog);

	initEventDispatcher();
	handleDelay();
}

void M_LaEmoji::initEventDispatcher()
{
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = std::bind(&M_LaEmoji::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void M_LaEmoji::handleDelay()
{
	for (int i = 0; i < _pages.size(); ++i)
	{
		_pages.at(i)->setEmojiVisible(false);
	}
	activePage(0);
}

void M_LaEmoji::activePage(int deactivedPage)
{
	if (deactivedPage > 0)
	{
		if (deactivedPage == _pages.size()) return;
		_pages.at(deactivedPage - 1)->deActive();
	}
	if (deactivedPage <= _pages.size() - 1)
	{
		_pages.at(deactivedPage)->pageActive(_parentLayer,_animationType);
	}
	else return;
	return;
}

void M_LaEmoji::onMouseDown()
{
	if (_pages.at(_activitedPage)->isActived())
	{
		if (_activitedPage != _pages.size() - 1)
		{
			++_activitedPage;
			activePage(_activitedPage);
			return;
		}
		else
		{
			destroy();
			return;
		}
	}
}

void M_LaEmoji::addToScene(int zOrder)
{
	_parentLayer->addChild(this, zOrder);
	_thisDialog->setGlobalZOrder(zOrder);
	for (int i = 0; i < _pages.size(); ++i)
	{
		_pages.at(i)->resetOrder(zOrder + 1);
	}
	/*
	_parentLayer->addChild(_thisDialog, zOrder);
	
	for (int i = 0; i < _pages.size(); ++i)
	{
		_pages.at(i)->addToScene(_parentLayer, zOrder);
	}
	*/
}

void M_LaEmoji::setPosition(Vec2 pos)
{
	_thisDialog->setPosition(pos);
	for (int i = 0; i < _pages.size(); ++i)
	{
		_pages.at(i)->setPosition(pos);
	}
}

void M_LaEmoji::destroy()
{
	removeFromParent();
}