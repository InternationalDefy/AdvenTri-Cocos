#include "Ref2LaEmoji.h"

USING_NS_CC;

M_Emoji* M_Emoji::createWithEmojiData(SD_Emoji* emojidata)
{
	M_Emoji* emoji = new (std::nothrow) M_Emoji();
	if (emoji&&emoji->initWithFile(emojidata->getFileName()))
	{
		emoji->initWithData(emojidata);
		emoji->autorelease();
		return emoji;
	}
	CC_SAFE_DELETE(emoji);
	return nullptr;
}

void M_Emoji::initWithData(SD_Emoji* emojidata)
{
	_adjustSize = emojidata->getAdjustSize();
	_delayTime = emojidata->getTimeDelay();
	setScale(_adjustSize);
	_size = Vec2(getContentSize().width*_adjustSize, getContentSize().height*_adjustSize);
}
