#include "Ref2Animation.h"

bool SD_AnimationPack::init()
{
	_NumberOfAnimations = 0;
	return true;
}

void SD_AnimationPack::setKeyName(const std::string& key, const std::string& name)
{
	_keysName.insert(std::make_pair(key, name));
}

SD_AnimationPack* SD_AnimationPack::create()
{
	SD_AnimationPack* pRet = new(std::nothrow) SD_AnimationPack();
	if (pRet)
	{
		pRet->init();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}