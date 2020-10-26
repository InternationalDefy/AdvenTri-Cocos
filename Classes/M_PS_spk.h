#ifndef __M_PS_SPK__
#define __M_PS_SPK__

#include "cocos2d.h"
#include "M_pSkill.h"

class SD_pSkill;
class M_Player;

USING_NS_CC;

class M_PS_spk : public M_pSkill
{
private:
	std::string _laEmojiName;

	bool _actived;

	Animate* animation;

	void init(SD_pSkill* breed);
public:

	static M_PS_spk* create(SD_pSkill* breed);
	
	void active();
};
#endif