#include "Ref2MenuAnimationHandler.h"

using namespace cocos2d;

M_MenuAnimationHandler* M_MenuAnimationHandler::create()
{
	M_MenuAnimationHandler* pRet = new(std::nothrow) M_MenuAnimationHandler();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}
M_MenuAnimationHandler* s_eventHandler;
M_MenuAnimationHandler* M_MenuAnimationHandler::getInstance()
{
	if (!s_eventHandler)
	{
		s_eventHandler = M_MenuAnimationHandler::create();
	}
	return s_eventHandler;
}
void M_MenuAnimationHandler::init()
{
	_MapParsers.insert(std::make_pair(AdvenTriEnum::MenuAnimation::MEA_FORCE, MEAP_Force::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::MenuAnimation::MEA_FADEIN, MEAP_FadeIn::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::MenuAnimation::MQA_FORCE, MQAP_ForceOut::create()));
	_MapParsers.insert(std::make_pair(AdvenTriEnum::MenuAnimation::MQA_FADEOUT, MQAP_FadeOut::create()));
	return;
}

void M_MenuAnimationHandler::addMenuEnterAction(UI_Menu* menu, M_MenuAnimationParser* parser,SD_UIMenu* sd)
{
	menu->setEnterAction(parser->getMenuAnimation(menu, sd));
	return;
}
void M_MenuAnimationHandler::addMenuQuitAction(UI_Menu* menu, M_MenuAnimationParser* parser, SD_UIMenu* sd)
{
	menu->setQuitAction(parser->getMenuAnimation(menu, sd));
	return;
}
void M_MenuAnimationHandler::handleEandQAnimationToMenu(UI_Menu* menu, SD_UIMenu* sd)
{
	auto k = _MapParsers.at(
		AdvenTriEnum::changeStringToMenuAnimation(sd->getEnterAnimationType()));
	addMenuEnterAction(menu, k, sd);
	auto s = _MapParsers.at(
		AdvenTriEnum::changeStringToMenuAnimation(sd->getQuitAnimationType()));
	addMenuQuitAction(menu, s, sd);
	return;
}