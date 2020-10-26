#ifndef __SD_LISTENINGSET__
#define __SD_LISTENINGSET__

#include "Ref_DataBase.h"

class Entity;
class UI_Item;

using namespace cocos2d;

class SD_ListenerSet : public SD
{
private:
	ASSIGN_DATA(int, NumberOfDispatcher);
	ASSIGN_DATA(std::vector<std::string>, DispatcherName);
	ASSIGN_DATA(int, NumberOfCallback);
	ASSIGN_DATA(std::vector<std::string>, CallbackName);
private:
	bool init();
public:
	//CREATE_FUNC(SD_PlayerController);
	static SD_ListenerSet* create();

	void pushDispatcherName(const std::string& str)
	{
		_DispatcherName.push_back(str);
	}
	void pushCallbackName(const std::string& str)
	{
		_CallbackName.push_back(str);
	}

	void addToNode(Node* node); 
	void addToEntity(Entity* entity);
	void addToUIItem(UI_Item* item);
	//Ctrl_Player* createPctrlFromSD();
};

#endif