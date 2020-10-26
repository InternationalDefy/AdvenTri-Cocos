#ifndef __M_EMOJIENTERACTION_PARSER_FADEIN__
#define __M_EMOJIENTERACTION_PARSER_FADEIN__

#include "cocos2d.h"
using namespace cocos2d;

class M_Emoji;
class M_EmojiActionParser;

class M_EEP_FadeIn :public M_EmojiActionParser
{
private:
	void fadeInFunc(M_Emoji* emoji,float dt);
public:
	CREATE_EMOJIACTIONPARSER(M_EEP_FadeIn);
	CallFunc* getEnterAction(M_Emoji* emoji, float dt);
};

#endif