#ifndef __M_EMOJIACTION_HANDLER__
#define __M_EMOJIACTION_HANDLER__

#include "cocos2d.h"
#include "Ref_Enum.h"

class M_EmojiActionParser;
class M_Emoji;

using namespace cocos2d;

class M_EmojiActionHandler :public Ref
{
private:
	void init();
	static M_EmojiActionHandler* create();
	std::map<AdvenTriEnum::EmojiEnterAction, M_EmojiActionParser*> _MapParsers;

	void addEmojiEnterAction(M_Emoji* emoji, M_EmojiActionParser* parser, float time);
public:
	void handleEnterActionToEmoji(M_Emoji* emoji, SD_Emoji* sd);
	static M_EmojiActionHandler* getInstance();
};

#endif