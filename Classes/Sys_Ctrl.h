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
	����ģʽ��Sys_Ctrl�ĳ�ʼ���������һ��ִ��getIntance()ʱ���У�
	��ʼ������ControllerData��ControllerRef�������Ͻ������ʱ����û�н��
	*/
	static Sys_Ctrl* getInstance();
	/**
	ֱ�ӷ���_controllerList.at(id-1)
	��id��СΪ1�����Ϊ_controllerList.size()
	*/
	//Ctrl_Base* getControllerWithID(int ID);
	Ctrl_Base* getControllerWithName(const std::string& name);


	Ctrl_Player* getPlayerController(const std::string& name);
	
};

#endif