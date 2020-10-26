#ifndef __SD_NPC__
#define __SD_NPC__

#include "Ref_DataBase.h"
#include "Ref_Enum.h"

USING_NS_CC;

class SD_Npc : public SD
{
private:
	ASSIGN_STRING(TextureName);
	ASSIGN_STRING(AnimationPackName);
	ASSIGN_STRING(LanguagePackName);
	ASSIGN_STRING(PhysicsBodyName);
	ASSIGN_STRING(ListenerSetName);
	ASSIGN_STRING(UISetName);
	ASSIGN_STRING(ControllerName);
	std::map<AdvenTriEnum::DamageType, bool> VulnerableMap;
private:
	bool init();
public:
	void setVulnerable(AdvenTriEnum::DamageType type, bool isVulnerable);
	bool isVulnerable(AdvenTriEnum::DamageType type)
	{
		return VulnerableMap.at(type);
	}
	static SD_Npc* create();

	//setters & getters

};
#endif