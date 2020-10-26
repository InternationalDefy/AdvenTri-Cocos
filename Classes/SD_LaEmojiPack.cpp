#include "Ref2LaEmoji.h"

USING_NS_CC;

bool SD_LaEmojiPack::init()
{
	return true;
}

SD_LaEmojiPack* SD_LaEmojiPack::create()
{
	SD_LaEmojiPack* pRet = new(std::nothrow) SD_LaEmojiPack();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

void SD_LaEmojiPack::pushKey(const std::string& name)
{
	_keys.push_back(name);
	return;
}

void SD_LaEmojiPack::pushLaEmoji(const std::string& name)
{
	_laEmojis.push_back(name);
	return;
}

std::vector<std::string>* SD_LaEmojiPack::getKeys()
{
	return &_keys;
}
std::vector<std::string>* SD_LaEmojiPack::getLaEmojiNames()
{
	return &_laEmojis;
}