#include "Ref_Save.h"
#include "Ref_GameLayer.h"

using namespace cocos2d;

Entity_Stance Sys_Save::getSceneSave(const std::string& SceneTag,
	const std::string& EntityTag)
{
	auto key = SceneTag + EntityTag;
	return getInt(key);
}
void Sys_Save::__ClearAllSceneSave(Save_Slot slot)
{
	auto db = DB_GameLayer::getInstance();
	auto table = db->getTable();
	for (auto i = table->begin(); i != table->end(); ++i)
	{
		__ClearSceneSave(i->first, slot);
	}
}
void Sys_Save::__ClearSceneSave(const std::string& gameLayerName, Save_Slot slot)
{
	SD_GameLayer* sd = DB_GameLayer::getInstance()->getGameLayerSD(gameLayerName);
	for (auto i = 0; i < sd->getNumberOfEnemy(); ++i)
	{
		auto key = "Slot" + std::to_string(slot) + sd->getGameLayerTag() + sd->getEnemyItems()->at(i).itemTag;
		saveInt(key, 0);
	}
	for (auto i = 0; i < sd->getNumberOfNpc(); ++i)
	{
		auto key = "Slot" + std::to_string(slot) + sd->getGameLayerTag() + sd->getNpcItems()->at(i).itemTag;
		saveInt(key, 0);
	}
}
void Sys_Save::saveScene(const std::string& SceneTag, M_GameLayer* layer)
{
	for (auto i = layer->EntityState.begin(); i != layer->EntityState.end(); ++i)
	{
		auto key = SceneTag + i->first;
		auto value = i->second;
		saveInt(key, value);
	}
}