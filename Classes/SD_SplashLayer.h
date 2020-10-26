#ifndef __SD_SPLASHSCENE__	
#define __SD_SPLASHSCENE__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_SplashLayer : public SD
{
public:
	struct SD_Item_SplashScene
	{
		std::string image;
		Vec3 position;
		int localZorder;
		bool enableAction;
		bool enableListenerSet;
		std::string listenerSet;
		std::string actionType;
		int numberActionParam;
		std::vector<std::string> actionParam;
	};
private:
	ASSIGN_DATA(int, NumberOfSprite);
	std::vector<SD_Item_SplashScene> _item;
private:
	bool init();
public:

	static SD_SplashLayer* create();

	//setters & getters
	void pushItem(SD_Item_SplashScene item)
	{
		_item.push_back(item);
	}
	std::vector<SD_Item_SplashScene>* getItems()
	{
		return &_item;
	}
};
#endif