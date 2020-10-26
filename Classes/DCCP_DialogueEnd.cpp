#include "Ref2EventSystem.h"
#include "SD_callback.h"
#include "Ref_UI.h"
#include "Ref_LaEmoji.h"

using namespace cocos2d;

CREATE_CALLBACKPARSER(DCCP_DialogueEnd);

void DCCP_DialogueEnd::initWithStringData(SD_Callback* stringData)
{
	_eventName = stringData->getUprecivingEventName();
	return;
}

void DCCP_DialogueEnd::onCustomEvent(EventCustom* eventCustom)
{
	Page_Dialogue* page = dynamic_cast<Page_Dialogue*> (getParent()->getParent());
	UI_Item* item = dynamic_cast<UI_Item*> (getParent());
	item->responseItem();
	
	page->quitPage();

	updateLimit();
	return;
}