#ifndef __SD_UIITEM__	
#define __SD_UIITEM__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_UIItem : public SD
{
private:
	ASSIGN_DATA(int, NumberOfSprites);
	ASSIGN_STRING(Type);
	ASSIGN_STRING(ListenerSetName);
	std::vector<Vec2> OffSetPos;
	std::vector<std::string> TextureName;
	std::vector<std::string> AnimationPackName;
private:
	bool init();
public:

	static SD_UIItem* create();

	//setters & getters
	std::vector<Vec2>* getOffSetVec2(){ return &OffSetPos; }
	void pushOffSetVec2(Vec2 off)
	{
		OffSetPos.push_back(off);
	}
	std::vector<std::string>* getTextureName()
	{
		return &TextureName;
	}
	void pushTextureName(const std::string& name)
	{
		TextureName.push_back(name);
	}
	std::vector<std::string>* getAnimationPackName()
	{
		return &AnimationPackName;
	}
	void pushAnimationPackName(const std::string& name)
	{
		AnimationPackName.push_back(name);
	}
};
#endif