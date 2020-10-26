#ifndef __M_FLYINGENDFUNC_HANDLER__
#define __M_FLYINGENDFUNC_HANDLER__

#include "cocos2d.h"
#include "Ref_Enum.h"

class SD_ItemEntity;
class M_FlyEndFuncParser;
class M_ItemEntity;

using namespace cocos2d;

class M_FlyEndFuncHandler :public Ref
{
private:
	void init();
	static M_FlyEndFuncHandler* create();
	std::map<AdvenTriEnum::FlyEndCallfunc, M_FlyEndFuncParser*> _MapParsers;

	void addToItemState(M_ItemEntity* item, M_FlyEndFuncParser* parser, SD_ItemEntity* stringData);
public:
	void addFlyEndFuncToItem(M_ItemEntity* item, SD_ItemEntity* stringData);
	static M_FlyEndFuncHandler* getInstance();
};

#endif