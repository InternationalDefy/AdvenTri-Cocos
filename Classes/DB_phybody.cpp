#include "Ref2Physics.h"

USING_NS_CC;

void DB_Physics::getLine(const std::string& data)
{
	tempPStringData = PhysicsStringData::create();
	tempName = analyseMiddle(data);

	tempPStringData->setLimitedVelocity(std::atof(analyseMiddle(data).c_str()));
	tempPStringData->setDampingLinear(std::atof(analyseMiddle(data).c_str()));
	tempPStringData->setLimitedAngularV(std::atof(analyseMiddle(data).c_str()));
	tempPStringData->setDampingAngular(std::atof(analyseMiddle(data).c_str()));
	tempPStringData->setBodyDynamic(std::atoi(analyseMiddle(data).c_str()));
	tempPStringData->setSize(std::atoi(analyseMiddle(data).c_str()));
	int k = tempPStringData->getSize();
	for (int i = 1; i <= k; ++i)
	{
		tempPStringData->pushShape(analyseMiddle(data));
		tempPStringData->pushSideX(std::atof(analyseMiddle(data).c_str()));
		tempPStringData->pushSideY(std::atof(analyseMiddle(data).c_str()));
	}
	analyseEndln(data);


	_table.insert(tempName,tempPStringData);
}

CREATE_DB(DB_Physics);

PhysicsBody* DB_Physics::getBody(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name)->createBody();
	}
	else
	{
		auto k = "Physics Body Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

