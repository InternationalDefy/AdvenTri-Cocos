#ifndef __M_ITEMSTATE_FLYENDFUNC_PARSER_DEFAULT__
#define __M_ITEMSTATE_FLYENDFUNC_PARSER_DEFAULT__

#include "cocos2d.h"
using namespace cocos2d;

class M_FlyEndFuncParser;
class M_ItemEntity;
class M_FEP_Default : public M_FlyEndFuncParser
{
private:
	void flyEndFunc(M_ItemEntity* item);
public:
	CREATE_FLYINGENDFUNCPARSER(M_FEP_Default);
	CallFunc* getFlyEndFunc(M_ItemEntity* item, SD_ItemEntity* sd);
};


#endif