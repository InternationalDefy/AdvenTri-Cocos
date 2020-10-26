#ifndef __M_ITEMSTATE_USEFUNC_PARSER_DAMAGETOSELF__
#define __M_ITEMSTATE_USEFUNC_PARSER_DAMAGETOSELF__

#include "cocos2d.h"
using namespace cocos2d;

class M_UseFuncParser;
class M_ItemState;
class M_UFP_DamageToSelf : public M_UseFuncParser
{
private:
	void useFunc(M_ItemState* item, SD_Item* sd);
public:
	CREATE_USEFUNCPARSER(M_UFP_DamageToSelf);
	CallFunc* getUseFunc(M_ItemState* item, SD_Item* sd);
};


#endif