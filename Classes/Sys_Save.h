#ifndef __SYS_SAVE__
#define __SYS_SAVE__

#include "DataBase.h"
#include "cocos2d.h"

#define MAX_SAVE_SLOT 3

using namespace cocos2d;

typedef unsigned int Save_Slot;
/*
Entity_Stance在于用一个数表示实体的多种状态。
A1A2A3
A3 0存活 1死亡
A2 A1 高位用于表示其他的状态和不同的含义。
*/
typedef unsigned int Entity_Stance;

class M_GameLayer;
class SD_GameLayer;
class DB_GameLayer;
class M_Player;
/*
完成了存档系统的基础操作，以下操作尚未实现
(即将完成)1：存档系统与场景系统的联动
2：存档系统与主角类联动
3：特殊存档信息的清空
4：存档覆盖问题和需要添加的TalkBox
*/
class Sys_Save :public Ref
{
private:
	Save_Slot _saveslot;
	void __SaveSlotClear(Save_Slot);
public:
	void clearAllSave();
	void clearSlot(Save_Slot);
	void clearCurrentSlot();
private:
	bool __SlotUsed(Save_Slot);
public:
	/*
	@1`对SceneTag的改变可以实现跨场景传递信息。
	@2`Entity_Stance在于用一个数表示实体的多种状态。
	A1A2A3
	A3 0存活 1死亡
	A2 A1 高位用于表示其他的状态和不同的含义。
	*/
	Entity_Stance getSceneSave(const std::string& SceneTag, 
		const std::string& EntityTag);
	void __ClearAllSceneSave(Save_Slot slot);
	void __ClearSceneSave(const std::string& sceneName,Save_Slot slot);
	void saveScene(const std::string& SceneTag, M_GameLayer*);
	void savePlayerData(M_Player*);
	void __ClearPlayerData(Save_Slot);
public:
	void saveString(const std::string& key, const std::string value);
	std::string getString(const std::string& key);
	void saveInt(const std::string& key, int value);
	int getInt(const std::string& key);
	void saveFloat(const std::string& key, float value);
	float getFloat(const std::string& key);
private:
	static Sys_Save* create();
	void init();
public:
	static Sys_Save* getInstance();	
	void setSaveSlot(int slot);
};

#endif 