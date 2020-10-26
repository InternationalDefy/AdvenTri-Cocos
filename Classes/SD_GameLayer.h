#ifndef __SD_GAMELAYER__	
#define __SD_GAMELAYER__

#include "Ref_DataBase.h"

USING_NS_CC;

class SD_GameLayer : public SD
{
public:
	struct SD_Item_Border
	{
		float height;
		float width;
		Vec2 position;
	};
	struct SD_Item_Entity
	{
		Vector<String*> scripts;
		std::string itemName;
		std::string itemTag;
		Vec3 position3D;
		int localZOrder;
		int numberOfScripts;
	};
	struct SD_Item_BackGround
	{
		Vector<String*> scripts;
		std::string image;
		int numberOfScripts;
		int localZOrder;
		Vec3 position3D;
		bool enableAction;
		std::string actionType;
		int numberOfActionParam;
		Vector<String*> actionParams;
		bool enableListener;
		std::string listenerSetName;
	};
private:
	ASSIGN_DATA(int, NumberOfNpc);
	ASSIGN_DATA(int, NumberOfEnemy);
	ASSIGN_DATA(int, NumberOfBackGround);
	ASSIGN_DATA(int, NumberOfPhysicsBorder);
	ASSIGN_STRING(ListenerSetName);
	ASSIGN_STRING(GameLayerTag);
	std::vector<SD_Item_Border> _BorderItem;
	std::vector<SD_Item_Entity> _NpcItem;
	std::vector<SD_Item_Entity> _EnemyItem;
	std::vector<SD_Item_BackGround> _BackgroundItem;
private:
	bool init();
public:

	static SD_GameLayer* create();

	//setters & getters
	void pushBorderItem(SD_Item_Border item)
	{
		_BorderItem.push_back(item);
	}
	std::vector<SD_Item_Border>* getBorderItems()
	{
		return &_BorderItem;
	}
	void pushNpcItem(SD_Item_Entity item)
	{
		_NpcItem.push_back(item);
	}
	std::vector<SD_Item_Entity>* getNpcItems()
	{
		return &_NpcItem;
	}
	void pushEnemyItem(SD_Item_Entity item)
	{
		_EnemyItem.push_back(item);
	}
	std::vector<SD_Item_Entity>* getEnemyItems()
	{
		return &_EnemyItem;
	}
	void pushBackgroundItem(SD_Item_BackGround item)
	{
		_BackgroundItem.push_back(item);
	}
	std::vector<SD_Item_BackGround>* getBackGroundItems()
	{
		return &_BackgroundItem;
	}
};
#endif