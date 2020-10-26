#ifndef __CONTROLLER_SYSTEM_H__	
#define __CONTROLLER_SYSTEM_H__

class Ctrl_Base;
class Ctrl_Player;
class DB_Ctrl;
class DB_PlayerController;
class Ctrl_MenuRandom;

USING_NS_CC;

class Sys_Ctrl	: public Ref
{
private:
	
	Ctrl_Base* _controllerTemp;
	//Vector<Ctrl_Base*> _controllerList;

	DB_Ctrl* _controllerData;
	DB_PlayerController* _playerControllerData;
	static Sys_Ctrl* create();
	void init();

	int changeControllerTypeNameToNum(const std::string & name);
	Ctrl_Base* handleControllerType(const std::string& name);
	
public:
	/*
	单例模式，Sys_Ctrl的初始化操作早第一次执行getIntance()时进行；
	初始化访问ControllerData和ControllerRef，方法上解耦，但是时间上没有解耦；
	*/
	static Sys_Ctrl* getInstance();
	/**
	直接返回_controllerList.at(id-1)
	固id最小为1，最大为_controllerList.size()
	*/
	//Ctrl_Base* getControllerWithID(int ID);
	Ctrl_Base* getControllerWithName(const std::string& name);


	Ctrl_Player* getPlayerController(const std::string& name);
	
};

#endif