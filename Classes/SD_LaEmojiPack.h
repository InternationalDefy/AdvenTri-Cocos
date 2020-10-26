#ifndef __SD_LAEMOJIPACK__
#define __SD_LAEMOJIPACK__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_LaEmojiPack : public SD
{
private:
	std::vector<std::string> _keys;
	std::vector<std::string> _laEmojis;
private:
	bool init();
public:
	void pushKey(const std::string& name);
	void pushLaEmoji(const std::string& name);
	std::vector<std::string>* getKeys();
	std::vector<std::string>* getLaEmojiNames();
	static SD_LaEmojiPack* create();
};

#endif