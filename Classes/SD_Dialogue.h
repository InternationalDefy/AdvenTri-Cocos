#ifndef __SD_DIALOGUE__
#define __SD_DIALOGUE__

#include "cocos2d.h"
#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_PageDialogue :public SD
{
private:
	ASSIGN_STRING(BackGroundName);
	ASSIGN_STRING(CharIconName);
	ASSIGN_DATA(Vec2, CharIconOffset);
	ASSIGN_STRING(LaEmojiName);
	ASSIGN_DATA(Vec2, LaEmojiPosition);
	ASSIGN_DATA(int, NumberOfItems);
	ASSIGN_STRING(LaCtrlName1);
	ASSIGN_STRING(LaCtrlName2);
	ASSIGN_DATA(int, LaCtrlOpacity1);
	ASSIGN_DATA(int, LaCtrlOpacity2);
	ASSIGN_DATA(Vec2, LaCtrlOffSet1);
	ASSIGN_DATA(Vec2, LaCtrlOffSet2);
	ASSIGN_STRING(EnterActionType);
	ASSIGN_STRING(ExitActionType)
private:
	Vector<String*> EnterActionParams;
	Vector<String*> ExitActionParams;
	std::vector<std::string> DiaCtrlItemNames;
	std::vector<Vec2> DiaCtrlItemOffSet;
	std::vector<int> DiaCtrlItemOpacity;
public:
	void pushDiaCtrlItemOpacity(int x){ DiaCtrlItemOpacity.push_back(x); }
	std::vector<int>* getDiaCtrlItemOpacity(){ return &DiaCtrlItemOpacity; }
	void pushDiaCtrlItemName(const std::string& name){ DiaCtrlItemNames.push_back(name); }
	std::vector<std::string>* getDiaCtrlItemNames(){ return &DiaCtrlItemNames; }
	void pushDiaCtrlItemOffSet(Vec2 pos){ DiaCtrlItemOffSet.push_back(pos); }
	std::vector<Vec2>* getDiaCtrlItemOffSet(){ return &DiaCtrlItemOffSet; }
	void pushEnterActionParam(const std::string& param){ EnterActionParams.pushBack(String::create(param)); }
	void pushExitActionParam(const std::string& param){ ExitActionParams.pushBack(String::create(param)); }
	Vector<String*>* getEnterActionParams(){ return &EnterActionParams; }
	Vector<String*>* getExitActionParams(){ return &ExitActionParams; }
private:
	bool init();
public:
	static SD_PageDialogue* create();
};

class SD_Dialogue :public SD
{
	ASSIGN_DATA(Vec2, OnSetPosition);
	ASSIGN_DATA(int, NumberOfPages);
	ASSIGN_DATA(int, Opacity);
	ASSIGN_STRING(EnterActionType);
	ASSIGN_STRING(ExitActionType)
private:
	Vector<String*> EnterActionParams;
	Vector<String*> ExitActionParams;
public:
	void pushEnterActionParam(const std::string& param){ EnterActionParams.pushBack(String::create(param)); }
	void pushExitActionParam(const std::string& param){ ExitActionParams.pushBack(String::create(param)); }
	Vector<String*>* getEnterActionParams(){ return &EnterActionParams; }
	Vector<String*>* getExitActionParams(){ return &ExitActionParams; }
private:
	Vector<SD_PageDialogue*> _Pages;
public:
	void pushPageSD(SD_PageDialogue* sd){ _Pages.pushBack(sd); }
	Vector<SD_PageDialogue*>* getPageSD(){ return &_Pages; }
private:
	bool init();
public:
	static SD_Dialogue* create();
};

#endif