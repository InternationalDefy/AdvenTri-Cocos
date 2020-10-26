#ifndef __M_ITEMSTATE_DROPFUNC_PARSER_DEFAULT__
#define __M_ITEMSTATE_DROPFUNC_PARSER_DEFAULT__

#include "cocos2d.h"
using namespace cocos2d;

class M_DropFuncParser;
class M_ItemState;
class M_DFP_Default : public M_DropFuncParser
{
private:
	void dropFunc(M_ItemState* item);
public:
	CREATE_DROPFUNCPARSER(M_DFP_Default);
	CallFunc* getDropFunc(M_ItemState* item, SD_ItemState* sd);
};


#endif