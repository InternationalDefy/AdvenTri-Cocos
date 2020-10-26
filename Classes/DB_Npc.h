#ifndef __DB_NPC__
#define __DB_NPC__

#include "Ref_DataBase.h"

class SD_Npc;

USING_NS_CC;

class DB_Npc : public DB
{
private:
	/*
	int n; int m;int numberCount;

	SD_Emoji* emojiTemp;

	SD_Dialog* dialogTemp;

	int tempInt;
	std::string tempName;

	std::string ReadFileToString(std::string fileName);

	void ParseEmoji(std::string stringName);
	void ParseDialog(std::string stringName);
	void PaeseLanguageDataByReference(std::string stringName);

	void ParseLanguageReference(std::string stringName);

	void HandleEmojiDataType(int type, std::string data);
	void HandleDialogDataType(int type, std::string data);
	void HandleLanguageDataType(SD_LaEmoji* laEmojiList,int type, std::string data);

	void HandleLanguageReferenceType(int type, std::string data);
	Map<std::string, SD_Emoji*> _emojiTable;
	Map<std::string, SD_Dialog*> _dialogTable;
	Vector<SD_LaEmoji*> _laEmojiListData;
	Vector<String*> _languageAddressData;
	*/
	SD_Npc* tempSD;
	std::string tempName;

	Map<std::string, SD_Npc*> _table;
public:
	std::string useString(){ return "Table_NpcBreed.csv"; }
	int HeadLines()	{ return 3; }

	void getLine(const std::string& data);

	static DB_Npc* create();
	static DB_Npc* getInstance();

	SD_Npc* getNpcBreed(const std::string& name);
};

#endif