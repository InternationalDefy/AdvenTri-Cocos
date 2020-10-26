#ifndef __LA_EMOJI_SYSTEM_H__	
#define __LA_EMOJI_SYSTEM_H__

#include "cocos2d.h"

class DB_LaEmoji;
class DB_Dialog;
class DB_Emoji;
class DB_LaEmojiPack;

class M_LaEmojiPack;
class M_LaEmoji;
class M_Emoji;

class M_EmojiActionHandler;
class M_EmojiActionParser;
class M_ActionHandler;

USING_NS_CC;

class Sys_LaEmoji	: public Ref
{
	friend class M_LaEmoji;
private:

	Vector<M_Emoji*> _tempEmojis;
	
	DB_LaEmoji* _dbLaEmoji;
	DB_Emoji* _dbEmoji;
	DB_Dialog* _dbDialog;
	DB_LaEmojiPack* _dbPack;

	M_ActionHandler* _actionHandler;

	M_EmojiActionHandler* _eaHandler;

	static Sys_LaEmoji* create();

	void pagesInit(M_LaEmoji* laEmoji,SD_LaEmoji* sd);
	/*
	Vector<M_Emoji*> _emojisData;
	Vector<M_Dialog*> _dialogsData;
	Vector<SD_LaEmoji*> _laEmojiLists;
	
	void LoadEmojis();
	void LoadDialogs();
	void LoadLaEmojiLists();
	*/
public:
	virtual void init();
	static Sys_LaEmoji* getInstance();
	
	M_LaEmojiPack* getLaEmojiPack(const std::string& name);
	M_LaEmoji* getLaEmoji(const std::string& name);
};

#endif