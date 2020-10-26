#include "Ref_Save.h"

using namespace cocos2d;
/*
这个的实现和场景类沟通 主角类沟通 技能信息类沟通等有关，需要使用它们的具体实现函数。
*/
void Sys_Save::__SaveSlotClear(Save_Slot slot)
{
	__ClearAllSceneSave(slot);
	__ClearPlayerData(slot);
	/*
	注意！这里的操作是将存档栏位还原为未使用状态。
	除此之外，在存档进行读取或者选择栏位的时候，也需要验证此烂尾是否为未使用状态。
	*/
	std::string key = "Slot" + std::to_string(slot) + "Used";
	UserDefault::getInstance()->setBoolForKey(key.c_str(), FALSE);
}
bool Sys_Save::__SlotUsed(Save_Slot slot)
{
	std::string key = "Slot" + std::to_string(slot) + "Used";
	bool value = UserDefault::getInstance()->getBoolForKey(key.c_str(), FALSE);
	return value;
}
/*
清除所有的存档，这个操作在Debug时可能会使用，通常游戏中不应当被调用。
*/
void Sys_Save::clearAllSave()
{
	for (Save_Slot i = 0; i < MAX_SAVE_SLOT; ++i)
	{
		clearSlot(i);
	}
	//Reset Statistics Data;
}
void Sys_Save::clearSlot(Save_Slot slot)
{
	__SaveSlotClear(slot);
}
void Sys_Save::clearCurrentSlot()
{
	__SaveSlotClear(_saveslot);
}

void Sys_Save::saveString(const std::string& key, const std::string value)
{
	UserDefault::getInstance()->setStringForKey(key.c_str(), value);
}
std::string Sys_Save::getString(const std::string& key)
{
	auto str = UserDefault::getInstance()->getStringForKey(key.c_str(), "Nope!");
	if (str != "Nope!")
	{
		return str;
	}
	log("String get Failed!");
}
void Sys_Save::saveInt(const std::string& key, int value)
{
	UserDefault::getInstance()->setIntegerForKey(key.c_str(), value);
}
int Sys_Save::getInt(const std::string& key)
{
	auto value = UserDefault::getInstance()->getIntegerForKey(key.c_str(), -1);
	if (value != -1)
	{
		return value;
	}
	log("Int get Failed!");
}
void Sys_Save::saveFloat(const std::string& key, float value)
{
	UserDefault::getInstance()->setFloatForKey(key.c_str(), value);
}
float Sys_Save::getFloat(const std::string& key)
{
	auto value = UserDefault::getInstance()->getFloatForKey(key.c_str(), -1);
	if (value != -1)
	{
		return value;
	}
	log("Float get Failed!");
}

void Sys_Save::init()
{
	_saveslot = UserDefault::getInstance()->getIntegerForKey("Save_Slot", 0);
}

void Sys_Save::setSaveSlot(int slot)
{
	if (__SlotUsed(slot))
	{
		/*
		Get Something Like A 弹窗 是否删除？
		此弹窗需要一个事件监听机制且吞噬所有的touch
		*/
		return;
	}
	_saveslot = slot;
	UserDefault::getInstance()->setIntegerForKey("Save_Slot", slot);
}
CREATE_DB(Sys_Save);