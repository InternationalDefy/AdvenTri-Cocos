#ifndef __M_DROPFUNC_HANDLER__
#define __M_DROPFUNC_HANDLER__

#include "cocos2d.h"
#include "Ref_Enum.h"

class SD_ItemState;
class M_ItemState;
class M_DropFuncParser;

using namespace cocos2d;

class M_DropFuncHandler :public Ref
{
private:
	void init();
	static M_DropFuncHandler* create();
	std::map<AdvenTriEnum::ItemDropCallfunc, M_DropFuncParser*> _MapParsers;

	void addToItemState(M_ItemState* item,M_DropFuncParser* parser,SD_ItemState* stringData);
public:
	void addDropFuncToItem(M_ItemState* item,SD_ItemState* stringData);
	static M_DropFuncHandler* getInstance();
};

#endif