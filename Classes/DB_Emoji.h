#ifndef __DB_EMOJI__	
#define __DB_EMOJI__

#include "Ref_DataBase.h"

class SD_Emoji;

using namespace cocos2d;

class DB_Emoji :public DB
{
private:
	SD_Emoji* tempSD;
	std::string tempName;

	Map<std::string, SD_Emoji*> _table;
public:
	std::string useString(){ return "Table_Emoji.csv"; }
	void getLine(const std::string& data);

	static DB_Emoji* create();
	static DB_Emoji* getInstance();

	SD_Emoji* getEmojiSD(const std::string& name);
};

#endif