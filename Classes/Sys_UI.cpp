#include "Ref2UI.h"
#include "Ref_EventSystem.h"
#include "Ref_LaEmoji.h"

using namespace cocos2d;

CREATE_DB(Sys_UI);

void Sys_UI::init()
{
	_uimenuDB = DB_UIMenu::getInstance();
	_uiitemDB = DB_UIItem::getInstance();
	_dialogueDB = DB_Dialogue::getInstance();
	_menuenterHandler = M_MenuAnimationHandler::getInstance();
	_actionHandler = M_ActionHandler::getInstance();
	return;
}
UI_Menu* Sys_UI::getUIMenu(const std::string& name)
{
	auto sd = _uimenuDB->getUIMenuSD(name);
	if (sd)
	{
		return createUiMenuWithStringData(sd);
	}
	log("Havnet get A sd!");
	return NULL;
}
UI_Menu* Sys_UI::createUiMenuWithStringData(SD_UIMenu* sd)
{
	auto menu = UI_Menu::create();
	menu->setEnterInstance(sd->getCallActived());
	menu->setOnSetLocalZOrder(sd->getZOrder());
	//addTO UI LAYER and Set Z Order
	_menuenterHandler->handleEandQAnimationToMenu(menu, sd);
	for (auto i = 0; i < sd->getNumberOfItems(); ++i)
	{
		auto itm = createUiItemWithStringData(sd->getUIItemStringData()->at(i),
			menu,sd->isActiveEnterAnimation()->at(i));
		menu->addItem(itm);
		itm->setOpacity(sd->getOffSetOpecity()->at(i));
		itm->setPosition(sd->getOffSetPosition()->at(i));
	}
	return menu;
}
UI_Item* Sys_UI::getUIItem(const std::string& name)
{
	auto sd = _uiitemDB->getUIItemSD(name);
	if (sd)
	{
		return createUiItemWithStringData(sd, NULL, TRUE);
	}
	log("Havent get a sd!");
	return NULL;
}
UI_Item* Sys_UI::createUiItemWithStringData(SD_UIItem* sdi, UI_Menu* menu, bool indiActive)
{
	auto item = UI_Item::create();
	item->setType(sdi->getType());
	auto k = sdi->getNumberOfSprites();

	Sys_Event::getInstance()->addListenerSetTo(item, sdi->getListenerSetName());

	item->setIndiActive(indiActive);
	for (auto i = 0; i < k; ++i)
	{
		auto sp = Sprite::create(sdi->getTextureName()->at(i));
		sp->setPosition(sdi->getOffSetVec2()->at(i));
		item->pushSprite(sp);
		/*
		auto pkg = DB_AnimationPack::getInstance()->getAnimationPack(sdi->getAnimationPackName()->at(i));
		item->pushEnterAction(pkg->getAnimation("Enter"));
		item->pushQuitAction(pkg->getAnimation("Quit"));
		item->pushResponseBeginAction(pkg->getAnimation("ResponseBegin"));
		item->pushResponseEndAction(pkg->getAnimation("ResponseEnd"));
		*/
	}
	return item;
	//add Some Menu Active Using Handler && Parser;
}

M_Dialogue* Sys_UI::getDialogue(const std::string& name)
{
	auto sd = _dialogueDB->getDialogueSD(name);
	if (sd)
	{
		return createMDialogueWithStringData(sd);
	}
	log("Havent get a sd!");
	return NULL;
}
M_Dialogue* Sys_UI::createMDialogueWithStringData(SD_Dialogue* sd)
{
	auto temp = M_Dialogue::create();
	temp->setPosition(sd->getOnSetPosition());
	auto act = _actionHandler->getAction(temp,
		sd->getEnterActionType(), sd->getEnterActionParams());
	temp->setEnterAction(act);
	auto act2 = _actionHandler->getAction(temp,
		sd->getExitActionType(), sd->getExitActionParams());
	temp->setQuitAction(act2);
	temp->setCascadeOpacityEnabled(TRUE);
	temp->setOpacity(sd->getOpacity());
	for (auto i = 0; i < sd->getNumberOfPages(); ++i)
	{
		auto sdp = sd->getPageSD()->at(i);
		auto page = createPageDialogueWithStringData(sdp);
		temp->pushPage(page);
		page->setDialogue(temp);
	}
	return temp;
}
Page_Dialogue* Sys_UI::createPageDialogueWithStringData(SD_PageDialogue* sd)
{
	auto temp = Page_Dialogue::create();
	temp->setBackGround(Sprite::create(sd->getBackGroundName()));
	auto chi = Sprite::create(sd->getCharIconName());
	chi->setPosition(sd->getCharIconOffset());
	temp->setCharIcon(chi);
	auto laEmoji = Sys_LaEmoji::getInstance()->getLaEmoji(sd->getLaEmojiName());
	laEmoji->setPosition(sd->getLaEmojiPosition());
	temp->setLaEmoji(laEmoji);
	auto laCtrl1 = getUIItem(sd->getLaCtrlName1());
	laCtrl1->setPosition(sd->getLaCtrlOffSet1());
	temp->setLastPageLaCtrlItem(laCtrl1);
	auto laCtrl2 = getUIItem(sd->getLaCtrlName2());
	laCtrl2->setPosition(sd->getLaCtrlOffSet2());
	temp->setNextPageLaCtrlItem(laCtrl2);

	auto act = _actionHandler->getAction(temp,
		sd->getEnterActionType(), sd->getEnterActionParams());
	temp->setEnterAction(act);
	auto act2 = _actionHandler->getAction(temp,
		sd->getExitActionType(), sd->getExitActionParams());
	temp->setQuitAction(act2);
	temp->setCascadeOpacityEnabled(TRUE);

	for (int i = 0; i < sd->getDiaCtrlItemNames()->size(); ++i)
	{
		auto item = getUIItem(sd->getDiaCtrlItemNames()->at(i));
		item->setPosition(sd->getDiaCtrlItemOffSet()->at(i));
		item->setOpacity(sd->getDiaCtrlItemOpacity()->at(i));
		temp->pushItem(item);
	}
	return temp;
}