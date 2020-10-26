#ifndef __M_EMOJIACTION_PARSER__
#define __M_EMOJIACTION_PARSER__

#define CREATE_EMOJIACTIONPARSER(__TYPE__) \
static __TYPE__* __TYPE__::create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
						    { \
        return pRet; \
						    } \
																																																															    else \
																																																															    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
																																																															    } \
} \

#include "cocos2d.h"

using namespace cocos2d;

class M_Emoji;

class M_EmojiActionParser :public Ref
{
private:
public:
	CREATE_EMOJIACTIONPARSER(M_EmojiActionParser);
	virtual CallFunc* getEnterAction(M_Emoji* emoji, float time);
};

#endif