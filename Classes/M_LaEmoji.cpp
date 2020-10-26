
#include "Ref2LaEmoji.h"

USING_NS_CC;
//创建及初始化
/*
M_LaEmoji* M_LaEmoji::create(SD_LaEmoji* laEmojiList)
{
	M_LaEmoji *piece = new (std::nothrow) M_LaEmoji();
	if (piece)
	{
		piece->init(laEmojiList);
		piece->autorelease();
		return piece;
	}
	CC_SAFE_DELETE(piece);
	return nullptr;
}
*/
M_LaEmoji* M_LaEmoji::create()
{
	M_LaEmoji *piece = new (std::nothrow) M_LaEmoji();
	if (piece&&piece->init())
	{
		piece->autorelease();
		return piece;
	}
	CC_SAFE_DELETE(piece);
	return nullptr;
}
bool M_LaEmoji::init()
{
	_currentPage = -1;
	_laEmojiActived = false;
	return true;
}
/**
设计思路
按顺序排列M_Emoji，过了Size.x换行，
按顺序排列M_Emoji，过了Size.y换页，
*/
/*
void M_LaEmoji::init(SD_LaEmoji* laEmojiList)
{
	//基础初始化
	_currentPage = 0;
	_laEmojiActived = false;

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
		_tempEmojis.at(i)->setPosition(Vec2(
			-width*0.5 + widthNow + _tempEmojis.at(i)->getSize().x*0.5,
			height*0.5 - heightNow - _tempEmojis.at(i)->getSize().y*0.5));
		widthNow += _tempEmojis.at(i)->getSize().x;
		pageOfPiece->push(_tempEmojis.at(i));
	}
	_pages.pushBack(pageOfPiece);
	_thisDialog = dialog;

	addChild(pageOfPiece);
	pageOfPiece->setLocalZOrder(1);
	addChild(dialog);

	initEventDispatcher();
	for (int i = 0; i < _pages.size(); ++i)
	{
		_pages.at(i)->setEmojiVisible(false);
	}
	//handleDelay();
}
*/

void M_LaEmoji::onEnter()
{
	Node::onEnter();
	_thisDialog->setLocalZOrder(getLocalZOrder());
	for (int i = 0; i < _pages.size(); ++i)
	{
		_pages.at(i)->resetOrder(getLocalZOrder() + 1);
	}
}
//事件监听
/*
void M_LaEmoji::initEventDispatcher()
{
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = std::bind(&M_LaEmoji::onMouseDown, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}*/
/*void M_LaEmoji::onMouseDown()
{
	if (_pages.at(_currentPage)->isActived())
	{
		if (_currentPage != _pages.size() - 1)
		{
			++_currentPage;
			activePage(_currentPage);
			return;
		}
		else
		{
			destroy();
			return;
		}
	}
}*/
//基础操作
/*
void M_LaEmoji::activePage(int deactivedPage)
{
	if (deactivedPage == _pages.size())
	{
		return;
	}
	_pages.at(deactivedPage)->pageActive(_animationType);
	if (!deactivedPage)
	{
		return;
	}
	_pages.at(deactivedPage - 1)->deActive();
	return;
}
*/
void M_LaEmoji::enter()
{
	_laEmojiActived = true;
	runAction(_enterAction);
	nextPage();
	return;
}
void M_LaEmoji::exit()
{
}
void M_LaEmoji::nextPage()
{
	if (_currentPage != _pages.size() - 1)
	{
		if (_currentPage != -1) _pages.at(_currentPage)->deActive();
		++_currentPage;
		_pages.at(_currentPage)->pageActive();
		return;
	}
	return;
}
void M_LaEmoji::lastPage()
{
	if (_currentPage)
	{
		_pages.at(_currentPage)->deActive();
		--_currentPage;
		_pages.at(_currentPage)->pageActive();
		return;
	}
	return;
}
bool M_LaEmoji::isPageActiveFinished()
{
	return _pages.at(_currentPage)->isActived();
}
void M_LaEmoji::destroy()
{
	removeFromParent();
}
void M_LaEmoji::update(float dt)
{
	if (!_laEmojiActived)
	{
		return;
	}
	_pages.at(_currentPage)->update(dt);
	return;
}
