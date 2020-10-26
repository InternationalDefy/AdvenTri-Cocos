#include "Ref2EventSystem.h"
#include "SD_dispatcher.h"

using namespace cocos2d;

CREATE_DISPATCHPARSER(DP_PositionWithin);

void DP_PositionWithin::initWithStringData(SD_Dispatcher* stringData)
{
	x = std::atof(stringData->getParams().at(0).c_str());
	y = std::atof(stringData->getParams().at(1).c_str());
	w = std::atof(stringData->getParams().at(2).c_str());
	h = std::atof(stringData->getParams().at(3).c_str());
	return;
}

void DP_PositionWithin::update(float dt)
{
	if (isLocked())
	{
		return;
	}
	if (getParentNode()->getBoundingBox().intersectsRect(Rect(x, y, w, h)))
	{
		//log("intersectsRect!");
		Sys_Event::getInstance()->dispatchEventWithName(getEventName());
		updateLimit();
	};
	return;
}