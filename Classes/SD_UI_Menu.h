#ifndef __SD_UIMENU__
#define __SD_UIMENU__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_UIItem;

class SD_UIMenu : public SD
{
private:
	ASSIGN_DATA(bool, CallActived);
	ASSIGN_DATA(int, ZOrder);
	ASSIGN_DATA(int, NumberOfItems);
	ASSIGN_STRING(EnterAnimationType);
	ASSIGN_STRING(QuitAnimationType);
	ASSIGN_DATA(int, NumberOfEnterAnimationParams);
	ASSIGN_DATA(int, NumberOfQuitAnimationParams);
	Vector<SD_UIItem*> UIItemStringData;
	std::vector<std::string> QuitAnimationParam;
	std::vector<std::string> EnterAnimationParam;
	std::vector<bool> ActiveEnterAnimation;
	std::vector<Vec2> OffSetPosition;
	std::vector<int> OffSetOpecity;
private:
	bool init();
public:

	static SD_UIMenu* create();

	//setters & getters
	void pushUIItemStringData(SD_UIItem* sd)
	{
		UIItemStringData.pushBack(sd);
	}
	void pushEnterAnimationParam(const std::string& param)
	{
		EnterAnimationParam.push_back(param);
	}
	void pushQuitAnimationParam(const std::string& param)
	{
		QuitAnimationParam.push_back(param);
	}
	void pushActiveEnterAnimation(bool t)
	{
		ActiveEnterAnimation.push_back(t);
	}
	void pushOffSetPosition(Vec2 pos)
	{
		OffSetPosition.push_back(pos);
	}
	void pushOffSetOpecity(int op)
	{
		OffSetOpecity.push_back(op);
	}
	Vector<SD_UIItem*>* getUIItemStringData()
	{
		return &UIItemStringData;
	}
	std::vector<std::string>* getEnterAnimationParam()
	{
		return &EnterAnimationParam;
	}
	std::vector<std::string>* getQuitAnimationParam()
	{
		return &QuitAnimationParam;
	}
	std::vector<bool>* isActiveEnterAnimation()
	{
		return &ActiveEnterAnimation;
	}
	std::vector<Vec2>* getOffSetPosition()
	{
		return &OffSetPosition;
	}
	std::vector<int>* getOffSetOpecity()
	{
		return &OffSetOpecity;
	}
};
#endif