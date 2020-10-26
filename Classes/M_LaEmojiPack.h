#ifndef __M_LAEMOJIPACK__
#define __M_LAEMOJIPACK__

#include "cocos2d.h"

using namespace cocos2d;

class M_LaEmoji;

class M_LaEmojiPack :public Node
{
private:
	std::map<std::string, std::string> _laEmojis;
public:
	CREATE_FUNC(M_LaEmojiPack);

	void addLaEmoji(const std::string& key, const std::string& name);
	M_LaEmoji* getLaEmoji(const std::string& key);
};

#endif