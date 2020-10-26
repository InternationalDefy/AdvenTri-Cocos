#include "Ref2pSkill.h"
#include "Ref_LaEmoji.h"

using namespace cocos2d;

void M_PS_spk::init(SD_pSkill* breed)
{
	_laEmojiName = breed->getStrings()->at(0)->getCString();
	_actived = FALSE;
}

M_PS_spk* M_PS_spk::create(SD_pSkill* breed)
{
	M_PS_spk* a_Breed = new (std::nothrow)M_PS_spk();
	if (a_Breed)
	{
		a_Breed->initCoolDown(breed);
		a_Breed->init(breed);
		a_Breed->autorelease();
		return a_Breed;
	}
	CC_SAFE_DELETE(a_Breed);
	return nullptr;
}

void M_PS_spk::active()
{
	if (!_actived)
	{
		log("talked!");
	}
}
