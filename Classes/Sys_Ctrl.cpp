#include "Ref2Controller.h"
#include "Ref_Enum.h"

USING_NS_CC;

void Sys_Ctrl::init()
{
	_controllerData = DB_Ctrl::getInstance();
	_playerControllerData = DB_PlayerController::getInstance();
}

int Sys_Ctrl::changeControllerTypeNameToNum(const std::string & name)
{
	if (name == "Base")
	{
		return 1;
	}
	else if (name == "Simple")
	{
		return 2;
	}
	else if (name == "MenuRandom")
	{
		return 3;
	}
	else if (name == "AI")
	{
		return 4;
	}
	else
	{
		log("UnKnown ControllerType");
	}
}

Ctrl_Base* Sys_Ctrl::getControllerWithName(const std::string& name)
{
	int type = changeControllerTypeNameToNum(_controllerData->getControllerSD(name)->getType());
	switch (type)
	{
	case 1:
		return Ctrl_Base::create(_controllerData->getControllerSD(name));
		break;
	case 2:
		return Ctrl_Simple::create(_controllerData->getControllerSD(name));
		break;
	case 3:
		return Ctrl_MenuRandom::create(_controllerData->getControllerSD(name));
		break;
	case 4:
		return Ctrl_AI::create(_controllerData->getControllerSD(name));
		break;
	default:
		break;
	}
}


Ctrl_Player* Sys_Ctrl::getPlayerController(const std::string& name)
{
	auto k = _playerControllerData->getPlayerControllerSD(name)->createPctrlFromSD();
	return k;
}
/*
Sys_Ctrl* Sys_Ctrl::create()
{
	Sys_Ctrl* controllerSystem = new (std::nothrow) Sys_Ctrl();
	if (controllerSystem)
	{
		controllerSystem->init();
		return controllerSystem;
	}
	CC_SAFE_DELETE(controllerSystem);
	return nullptr;
}*/
CREATE_DB(Sys_Ctrl);
/*
static Sys_Ctrl* s_ControllerSystem;

Sys_Ctrl* Sys_Ctrl::getInstance()
{
	if (!s_ControllerSystem)
	{
		s_ControllerSystem = Sys_Ctrl::create();
	}

	return s_ControllerSystem;
}*/