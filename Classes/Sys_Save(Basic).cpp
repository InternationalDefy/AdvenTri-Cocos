#include "Ref_Save.h"

using namespace cocos2d;
/*
�����ʵ�ֺͳ����๵ͨ �����๵ͨ ������Ϣ�๵ͨ���йأ���Ҫʹ�����ǵľ���ʵ�ֺ�����
*/
void Sys_Save::__SaveSlotClear(Save_Slot slot)
{
	__ClearAllSceneSave(slot);
	__ClearPlayerData(slot);
	/*
	ע�⣡����Ĳ����ǽ��浵��λ��ԭΪδʹ��״̬��
	����֮�⣬�ڴ浵���ж�ȡ����ѡ����λ��ʱ��Ҳ��Ҫ��֤����β�Ƿ�Ϊδʹ��״̬��
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
������еĴ浵�����������Debugʱ���ܻ�ʹ�ã�ͨ����Ϸ�в�Ӧ�������á�
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
		Get Something Like A ���� �Ƿ�ɾ����
		�˵�����Ҫһ���¼������������������е�touch
		*/
		return;
	}
	_saveslot = slot;
	UserDefault::getInstance()->setIntegerForKey("Save_Slot", slot);
}
CREATE_DB(Sys_Save);