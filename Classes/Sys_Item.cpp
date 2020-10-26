#include "Ref2ItemSystem.h"

USING_NS_CC;

void Sys_Item::init()
{
	_dbItemState = DB_ItemState::getInstance();
	_dbItemEntity = DB_ItemEntity::getInstance();
	_dpFuncHandler = M_DropFuncHandler::getInstance();
	_usFuncHandler = M_UseFuncHandler::getInstance();
	_feFuncHandler = M_FlyEndFuncHandler::getInstance();
	return;
}

M_ItemState* Sys_Item::getItemState(const std::string& name)
{
	auto is = M_ItemState::create();
	auto sd = _dbItemState->getItemStateSD(name);
	is->setSystem(this);
	is->setEntityName(sd->getItemEntity());
	is->setItemName(sd->getItemName());
	//is->setUISet();
	is->setUseTime(sd->getUsingTime());
	is->setUseAnimate(DB_Animate::getInstance()->getAnimate(sd->getUsingAnimateName()));
	is->setPickUpAnimate(DB_Animate::getInstance()->getAnimate(sd->getPickUpAnimate()));
	_dpFuncHandler->addDropFuncToItem(is, sd);
	_usFuncHandler->addUseFuncToItem(is, sd);
	return is;
}

M_ItemEntity* Sys_Item::getItemEntity(const std::string& name)
{
	auto sd = _dbItemEntity->getItemEntitySD(name);
	auto ie = M_ItemEntity::create(sd->getTextureName());
	ie->setItemName(sd->getItemName());
	ie->setItemStateName(sd->getItemState());
	ie->setExistingTime(sd->getTimeExist());
	if (sd->getPhysicsBodyName() != "") 
		ie->setPhysicsBody(DB_Physics::getInstance()->getBody(sd->getPhysicsBodyName()));
	if (sd->getDropController() != "")
		ie->setDropController(Sys_Ctrl::getInstance()->getControllerWithName(sd->getDropController()));
	if (sd->getFlyingController() != "")
		ie->setFlyController(Sys_Ctrl::getInstance()->getControllerWithName(sd->getFlyingController()));
	if (sd->getDropAnimateName() != "")
		ie->setThrowAnimate(DB_Animate::getInstance()->getAnimate(sd->getDropAnimateName()));
	_feFuncHandler->addFlyEndFuncToItem(ie, sd);
	return ie;
}

CREATE_DB(Sys_Item);
