#ifndef __M_ITEMSTATE_DROPFUNC_PARSER_FLYING__
#define __M_ITEMSTATE_DROPFUNC_PARSER_FLYING__

#include "cocos2d.h"
using namespace cocos2d;

class M_DropFuncParser;
class M_ItemState;
class M_DFP_Flying : public M_DropFuncParser
{
private:
	void dropFunc(M_ItemState* item);
public:
	CREATE_DROPFUNCPARSER(M_DFP_Flying);
	CallFunc* getDropFunc(M_ItemState* item, SD_ItemState* sd);
};


#endif