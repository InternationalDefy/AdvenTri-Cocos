#include "Ref2EventSystem.h"
#include "SD_callback.h"
#include "Ref_LaEmoji.h"
#include "Ref_UI.h"

using namespace cocos2d;

CREATE_CALLBACKPARSER(DCCP_LaCtrlRight);

void DCCP_LaCtrlRight::initWithStringData(SD_Callback* stringData)
{
	_eventName = stringData->getUprecivingEventName();
	return;
}

void DCCP_LaCtrlRight::onCustomEvent(EventCustom* eventCustom)
{
	Page_Dialogue* page = dynamic_cast<Page_Dialogue*> (getParent()->getParent());
	UI_Item* item = dynamic_cast<UI_Item*> (getParent());
	item->responseItem();
	M_LaEmoji* laEmoji = page->getLaEmoji(); 
	if (laEmoji->isActived())
	{
		if (laEmoji->isPageActiveFinished())
		{
			laEmoji->nextPage();
		}
	}
	else
	{
		laEmoji->enter();
	}
	updateLimit();
	return;
}