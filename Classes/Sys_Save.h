#ifndef __SYS_SAVE__
#define __SYS_SAVE__

#include "DataBase.h"
#include "cocos2d.h"

#define MAX_SAVE_SLOT 3

using namespace cocos2d;

typedef unsigned int Save_Slot;
/*
Entity_Stance������һ������ʾʵ��Ķ���״̬��
A1A2A3
A3 0��� 1����
A2 A1 ��λ���ڱ�ʾ������״̬�Ͳ�ͬ�ĺ��塣
*/
typedef unsigned int Entity_Stance;

class M_GameLayer;
class SD_GameLayer;
class DB_GameLayer;
class M_Player;
/*
����˴浵ϵͳ�Ļ������������²�����δʵ��
(�������)1���浵ϵͳ�볡��ϵͳ������
2���浵ϵͳ������������
3������浵��Ϣ�����
4���浵�����������Ҫ��ӵ�TalkBox
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
	@1`��SceneTag�ĸı����ʵ�ֿ糡��������Ϣ��
	@2`Entity_Stance������һ������ʾʵ��Ķ���״̬��
	A1A2A3
	A3 0��� 1����
	A2 A1 ��λ���ڱ�ʾ������״̬�Ͳ�ͬ�ĺ��塣
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