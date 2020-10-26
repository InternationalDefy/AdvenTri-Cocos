#include "Ref2LaEmoji.h"
#include "Ref_ActionHandler.h"

USING_NS_CC;

void Sys_LaEmoji::init()
{
	_dbDialog = DB_Dialog::getInstance();
	_dbEmoji = DB_Emoji::getInstance();
	_dbLaEmoji = DB_LaEmoji::getInstance();
	_eaHandler = M_EmojiActionHandler::getInstance();
	_actionHandler = M_ActionHandler::getInstance();
	_dbPack = DB_LaEmojiPack::getInstance();
}

M_LaEmoji* Sys_LaEmoji::getLaEmoji(const std::string& name)
{
	auto sd = _dbLaEmoji->getLaEmojiSD(name);
	auto laEmoji = M_LaEmoji::create();
	pagesInit(laEmoji, sd);
//	laEmoji->initEventDispatcher();
	for (int i = 0; i < laEmoji->_pages.size(); ++i)
	{
		laEmoji->_pages.at(i)->setEmojiVisible(false);
	}
	laEmoji->setCascadeOpacityEnabled(TRUE);
	return laEmoji;
}
void Sys_LaEmoji::pagesInit(M_LaEmoji* laEmoji,SD_LaEmoji* sd)
{
	_tempEmojis.clear();

	for (int i = 0; i < sd->getSdEmojis()->size(); ++i)
	{
		auto esd = sd->getSdEmojis()->at(i);
		auto k = M_Emoji::createWithEmojiData(esd);
		//_eaHandler->handleEnterActionToEmoji(k, esd);
		auto act = _actionHandler->getAction(k, esd->getEnterActionType(),esd->getEnterActionParam());
		k->setEnterAction(act);
		_tempEmojis.pushBack(k);
	}
	M_Dialog* dialog = M_Dialog::createWithDialogData(sd->getDialog());

	laEmoji->_enterAction = M_ActionHandler::getInstance()->getAction(laEmoji, sd->getAnimationName());
	laEmoji->_enterAction->retain();

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
				laEmoji->_pages.pushBack(pageOfPiece);
				laEmoji->addChild(pageOfPiece);
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
	laEmoji->_pages.pushBack(pageOfPiece);
	laEmoji->_thisDialog = dialog;

	laEmoji->addChild(pageOfPiece, 2);
	laEmoji->addChild(dialog,1);

	return;
}

M_LaEmojiPack* Sys_LaEmoji::getLaEmojiPack(const std::string& name)
{
	auto Ret = M_LaEmojiPack::create();
	auto sd = _dbPack->getLaEmojiPackSD(name);
	for (auto i = 0; i < sd->getKeys()->size(); ++i)
	{
		auto laEmoji = getLaEmoji(sd->getLaEmojiNames()->at(i));
		Ret->addLaEmoji(sd->getKeys()->at(i), sd->getLaEmojiNames()->at(i));
	}
	return Ret;
}

Sys_LaEmoji* Sys_LaEmoji::create()
{
	Sys_LaEmoji* laEmojiSystem = new (std::nothrow) Sys_LaEmoji();
	if (laEmojiSystem)
	{
		laEmojiSystem->init();
		return laEmojiSystem;
	}
	CC_SAFE_DELETE(laEmojiSystem);
	return nullptr;
}
static Sys_LaEmoji* s_LaEmojiSystem;
Sys_LaEmoji* Sys_LaEmoji::getInstance()
{
	if (!s_LaEmojiSystem)
	{
		s_LaEmojiSystem = Sys_LaEmoji::create();
	}

	return s_LaEmojiSystem;
}