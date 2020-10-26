#ifndef __DB_LAEMOJI__
#define __DB_LAEMOJI__

#include "Ref_DataBase.h"

class SD_LaEmoji;
class SD_Emoji;
class SD_Dialog;

USING_NS_CC;

class DB_LaEmoji : public DB
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
	SD_LaEmoji* tempSD;
	std::string tempName;

	Map<std::string, SD_LaEmoji*> _table;
public:
	std::string useString(){ return "Table_LaEmoji.csv"; }
	void getLine(const std::string& data);
	int HeadLines()	{ return 3; }
	
	static DB_LaEmoji* create();
	static DB_LaEmoji* getInstance();

	SD_LaEmoji* getLaEmojiSD(const std::string& name);
};

#endif