#include "Ref2EventSystem.h"
#include "SD_callback.h"
#include "Ref_UI.h"
#include "Ref_LaEmoji.h"

using namespace cocos2d;

CREATE_CALLBACKPARSER(DCCP_LaCtrlLeft);

void DCCP_LaCtrlLeft::initWithStringData(SD_Callback* stringData)
{
	_eventName = stringData->getUprecivingEventName();
	return;
}

void DCCP_LaCtrlLeft::onCustomEvent(EventCustom* eventCustom)
{
	Page_Dialogue* page= dynamic_cast<Page_Dialogue*> (getParent()->getParent());
	M_LaEmoji* laEmoji = page->getLaEmoji();
	UI_Item* item = dynamic_cast<UI_Item*> (getParent());
	item->responseItem();
	if (laEmoji->isActived())
	{
		if (laEmoji->isPageActiveFinished())
		{
			laEmoji->lastPage();
		}
	}
	updateLimit();
	return;
}