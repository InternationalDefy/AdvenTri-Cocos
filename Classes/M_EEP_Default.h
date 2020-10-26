#ifndef __M_EMOJIENTERACTION_PARSER_DEFAULT__
#define __M_EMOJIENTERACTION_PARSER_DEFAULT__

#include "cocos2d.h"
using namespace cocos2d;

class M_Emoji;
class M_EmojiActionParser;

class M_EEP_Default :public M_EmojiActionParser
{
private:
	void setFunc(M_Emoji* emoji);
public:
	CREATE_EMOJIACTIONPARSER(M_EEP_Default);
	CallFunc* getEnterAction(M_Emoji* emoji, float dt);
};

#endif