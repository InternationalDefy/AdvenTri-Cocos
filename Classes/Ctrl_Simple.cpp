#include "Ref2Controller.h"

using namespace cocos2d;

void Ctrl_Simple::move()
{
	_isActionRunning = TRUE;
	
	getEntity()->runAction(Sequence::create(dynamic_cast<FiniteTimeAction*>(_steps.at(_stepNow)),
		CallFunc::create(std::bind(&Ctrl_Simple::EntityRunEndCallback, this)), NULL));
		
	_stepNow += 1;
	if (_stepNow == _steps.size()) _stepNow = 0;
}

void Ctrl_Simple::initWithSD(SD_Ctrl* controllerData)
{
	_isActionRunning = false;
	_stepNow = 0;
	setDelay(controllerData->getDelta());
	for (int i = 0; i < controllerData->getLines()->size(); ++i)
	{
		ParseItemToSteps(this,controllerData->getLines()->at(i));
	}
}
/*
Vec2 Ctrl_Simple::getTargetVec2()
{
	return _targetVec2;
}

void Ctrl_Simple::DashByCallFunc(float x, float y)
{
	_targetVec2 = Vec2(x/sqrtf(x*x+y*y),y/sqrtf(x*x+y*y));
	dynamic_cast <M_Enemy*> (getEntity())->handleAction(AdvenTriEnum::EnemyAction::E_ACTION_DASH);
}
*/
void Ctrl_Simple::ParseItemToSteps(Ctrl_Simple* ctrl, SD_Item* item)
{
	ctrl->_typeTemp = ParseStringToType(item->getStrings()->at(0)->getCString());
	switch (ctrl->_typeTemp)
	{
	case 0:
		ctrl->_actionTemp = DelayTime::create(std::atof(item->getStrings()->at(1)->getCString()));
		break;
	case 1:
		ctrl->_actionTemp = MoveTo::create(
			std::atof(item->getStrings()->at(1)->getCString()),
			Vec2(Director::getInstance()->getVisibleSize().width*
			std::atof(item->getStrings()->at(2)->getCString()),
			Director::getInstance()->getVisibleSize().height*
			std::atof(item->getStrings()->at(3)->getCString())));
		break;
	case 2:
		ctrl->_actionTemp = MoveBy::create(
			std::atof(item->getStrings()->at(1)->getCString()),
			Vec2(Director::getInstance()->getVisibleSize().width*
			std::atof(item->getStrings()->at(2)->getCString()),
			Director::getInstance()->getVisibleSize().height*
			std::atof(item->getStrings()->at(3)->getCString())));
		break;
	case 3:
		break;
	case 4:
		break;
	/*case 5:
		ctrl->_actionTemp = CallFunc::create(std::bind(&Ctrl_Simple::DashByCallFunc, ctrl,
			std::atof(item->getStrings()->at(1)->getCString()),
			std::atof(item->getStrings()->at(2)->getCString())));
		break;
		*/
	default:
		break;
	}
	ctrl->_steps.pushBack(ctrl->_actionTemp);
}
/**
ParseItemToSteps函数可将stringdata中的item变为Action* step[i]存储
对码表如下
Wait:0;
MoveTo:1;
MoveBy:2;
Attack:3;?
Speak:4;?
Skill?
*/
int Ctrl_Simple::ParseStringToType(const std::string& stringOnGo)
{
	if (stringOnGo == "Wait")
	{
		return 0;
	}
	else if (stringOnGo == "MoveTo")
	{
		return 1;
	}
	else if (stringOnGo == "MoveBy")
	{
		return 2;
	}
	else if (stringOnGo == "Attack")
	{
		return 3;
	}
	else if (stringOnGo == "Speak")
	{
		return 4;
	}
	else if (stringOnGo == "DashBy")
	{
		return 5;
	}
}

void Ctrl_Simple::update(float dt)
{
	if (_isActionRunning)
	{
		return;
	}
	_count += dt;
	if (_count > _delay)
	{
		_count = 0;
		move();
	}
}