#ifndef __SD_SCENE__	
#define __SD_SCENE__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_Scene : public SD
{
public:
	struct SD_Item_Scene
	{
		Vector<String*> scripts;
		std::string itemName;
		int numberOfScripts;
	};
private:
	ASSIGN_DATA(int, NumberOfGameLayer);
	ASSIGN_DATA(int, NumberOfSplashScene);
	std::vector<SD_Item_Scene> _splashItem;
	std::vector<SD_Item_Scene> _layerItem;
private:
	bool init();
public:

	static SD_Scene* create();

	//setters & getters
	void pushSplashSceneItem(SD_Item_Scene item)
	{
		_splashItem.push_back(item);
	}
	std::vector<SD_Item_Scene>* getSplashSceneItems()
	{
		return &_splashItem;
	}
	void pushGameLayerItem(SD_Item_Scene item)
	{
		_layerItem.push_back(item);
	}
	std::vector<SD_Item_Scene>* getGameLayerItems()
	{
		return &_layerItem;
	}
};
#endif