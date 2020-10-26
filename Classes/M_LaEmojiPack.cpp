#include "Ref2LaEmoji.h"

using namespace cocos2d;

void M_LaEmojiPack::addLaEmoji(const std::string& key, const std::string& name)
{
	_laEmojis.insert(std::make_pair(key, name));
	return;
}

M_LaEmoji* M_LaEmojiPack::getLaEmoji(const std::string& key)
{
	if (&_laEmojis.at(key))
	{
		return Sys_LaEmoji::getInstance()->getLaEmoji(_laEmojis.at(key));
	}
	log("UNFOUND KEY LAEMOJI !");
}