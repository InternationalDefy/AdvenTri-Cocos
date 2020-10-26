#ifndef __SD_LAEMOJI__	
#define __SD_LAEMOJI__

#include "Ref_DataBase.h"

class SD_Dialog;
class SD_Emoji;

USING_NS_CC;

class SD_LaEmoji : public SD
{
private:
	ASSIGN_DATA(int, NumberOfEmoji);
	/*
	animation��һ����ʱ��ƣ��Ժ�����Enum��������ơ�
	**/
	ASSIGN_STRING(AnimationName);
	ASSIGN_DATA(SD_Dialog*, Dialog);
	Vector<SD_Emoji*> _emojis;
private:
	bool init();
public:

	static SD_LaEmoji* create();

	//setters & getters
	Vector<SD_Emoji*>* getSdEmojis()
	{ 
		return &_emojis; 
	}
	void pushSdEmoji(SD_Emoji* x)
	{ 
		_emojis.pushBack(x); 
	}
	//�˾���룬��ζ���ֵ����ϸϸ��Ʒζ��
	void setNothing(int x){ return; }
};
#endif