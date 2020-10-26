#ifndef __M_USEFUNC_HANDLER__
#define __M_USEFUNC_HANDLER__

#include "cocos2d.h"
#include "Ref_Enum.h"

class SD_ItemState;
class M_ItemState;
class M_UseFuncParser;
class SD_Item;

using namespace cocos2d;

class M_UseFuncHandler :public Ref
{
private:
	void init();
	static M_UseFuncHandler* create();
	std::map<AdvenTriEnum::ItemUseCallfunc, M_UseFuncParser*> _MapParsers;

	void addToItemState(M_ItemState* item, M_UseFuncParser* parser, SD_Item* strings);
public:
	void addUseFuncToItem(M_ItemState* item, SD_ItemState* stringData);
	static M_UseFuncHandler* getInstance();
};

#endif