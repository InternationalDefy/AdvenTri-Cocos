#ifndef __DB_LAEMOJIPACK__
#define __DB_LAEMOJIPACK__

#include "Ref_DataBase.h"

class SD_LaEmojiPack;

using namespace cocos2d;

class DB_LaEmojiPack :public DB
{
private:
	SD_LaEmojiPack* tempSD;
	std::string tempName;

	Map<std::string, SD_LaEmojiPack*> _table;
public:
	std::string useString(){ return "Table_LaEmojiPack.csv"; }
	void getLine(const std::string& data);

	static DB_LaEmojiPack* create();
	static DB_LaEmojiPack* getInstance();

	SD_LaEmojiPack* getLaEmojiPackSD(const std::string& name);
};

#endif