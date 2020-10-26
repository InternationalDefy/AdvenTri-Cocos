#include "Ref2LaEmoji.h"

using namespace cocos2d;

M_EmojiActionHandler* M_EmojiActionHandler::create()
{
	M_EmojiActionHandler* pRet = new(std::nothrow) M_EmojiActionHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_EmojiActionHandler* s_eventHandler;
M_EmojiActionHandler* M_EmojiActionHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_EmojiActionHandler::create();
	}
	return s_eventHandler;
}
void M_EmojiActionHandler::init()
{
	_MapParsers.insert(std::make_pair(AdvenTriEnum::EmojiEnterAction::EE_A_DEFAULT, M_EEP_Default::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::EmojiEnterAction::EE_A_FADEIN, M_EEP_FadeIn::create()));
	return;
}

void M_EmojiActionHandler::addEmojiEnterAction(M_Emoji* emoji, M_EmojiActionParser* parser, float time)
{
	emoji->setEnterAction(parser->getEnterAction(emoji,time));
	return;
}
void M_EmojiActionHandler::handleEnterActionToEmoji(M_Emoji* emoji, SD_Emoji* sd)
{
	/*
	auto k = _MapParsers.at(sd->getEnterAction());
	addEmojiEnterAction(emoji, k, sd->getTimeDelay());
	*/
	return;
}