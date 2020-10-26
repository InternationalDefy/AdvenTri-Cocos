#ifndef __M_ITEMSTATE_FLYENDFUNC_PARSER_BLAST__
#define __M_ITEMSTATE_FLYENDFUNC_PARSER_BLAST__

#include "cocos2d.h"
using namespace cocos2d;

class M_FlyEndFuncParser;
class M_ItemEntity;
class M_FEP_Blast : public M_FlyEndFuncParser
{
private:
	void flyEndFunc(M_ItemEntity* item);
public:
	CREATE_FLYINGENDFUNCPARSER(M_FEP_Blast);
	CallFunc* getFlyEndFunc(M_ItemEntity* item, SD_ItemEntity* sd);
};


#endif