#ifndef __M_NPC__
#define __M_NPC__

#include "cocos2d.h"
#include "Ref_Enum.h"
#include "Entity.h"

class M_AnimationPack;
class M_LaEmojiPack;
class M_LaEmoji;
class SD_Npc;

using namespace cocos2d;

class Entity;

class M_Npc :public Entity
{
private:
	M_LaEmojiPack* _laEmojiPack;
	//M_AnimationPack* _animationPack;
	M_LaEmoji* _currentLaEmoji;
	SD_Npc* _nbreed;
	std::string _currentLaEmojiName;
private:
	static void init(M_Npc* npc,SD_Npc* sd);
public:
	static M_Npc* create(const std::string& SDNpcName);
	static M_Npc* create(SD_Npc* sd);
private:
	void doHurt(AdvenTriEnum::DamageType type,int dam);
public:
	void onHurt(AdvenTriEnum::DamageType type, int dam);
private:
	void speak(M_LaEmoji* laEmoji, Vec2 pos);
public:
	void speakLaEmoji(const std::string& laEmojiName,Vec2 pos);
	void speakKey(const std::string& keyName,Vec2 pos);
public:
	void update(float dt);
};

#endif