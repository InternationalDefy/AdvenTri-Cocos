#ifndef __M_DH_ENTITYMOVETO__
#define __M_DH_ENTITYMOVETO__

#include "cocos2d.h"

class SD_Dispatcher;

using namespace cocos2d;

class DP_PositionWithin :public M_DispatchParser
{
private:
	float x; float y; float w; float h;
public:
	void update(float dt);
	void initWithStringData(SD_Dispatcher* stringData);

	static DP_PositionWithin* create(SD_Dispatcher* stringData);
};

#endif