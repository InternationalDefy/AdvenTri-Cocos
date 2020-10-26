#include "Ref2Npc.h"

SD_Npc* SD_Npc::create()
{
	SD_Npc *pRet = new (std::nothrow) SD_Npc();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

bool SD_Npc::init()
{
	_TextureName = "";
	_AnimationPackName = "";
	_LanguagePackName = "";
	_PhysicsBodyName = "";
	_ListenerSetName = "";
	_UISetName = "";
	_ControllerName = "";
	for (int i = 0; i <= 15; ++i)
	{
		auto k = AdvenTriEnum::DamageType(i);
		VulnerableMap.insert(std::make_pair(k, FALSE));
	}
	return true;
}

void SD_Npc::setVulnerable(AdvenTriEnum::DamageType type, bool isVulnearble)
{
	VulnerableMap.at(type) = isVulnearble;
	return;
}