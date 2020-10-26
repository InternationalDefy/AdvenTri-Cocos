#include "Ref2Animation.h"

USING_NS_CC;

void DB_Animate::getLine(const std::string& data)
{
	tempAnimationData = SD_Animate::create();
	tempName = analyseMiddle(data);
	int k = std::atoi(analyseMiddle(data).c_str());
	tempAnimationData->setDelay(std::atof(analyseMiddle(data).c_str()));
	tempAnimationData->setLoop(std::atoi(analyseMiddle(data).c_str()));
	tempAnimationData->setDelayLoop(std::atof(analyseMiddle(data).c_str()));
	for (int i = 1; i <= k; ++i)
	{
		tempAnimationData->pushFrameName(String::create(analyseMiddle(data)));
	}
	analyseEndln(data);
	_animationTable.insert(tempName, tempAnimationData);
}

CREATE_DB(DB_Animate);

Animate* DB_Animate::getAnimate(const std::string& key)
{
	if (_animationTable.at(key))
	{
		return _animationTable.at(key)->getAnimate();
	}
	else
	{
		auto k = "Animate Name " + key + " UNFOUND!";
		log(k.c_str());
	}
}

SD_Animate* DB_Animate::getAnimationData(const std::string& key)
{
	if (_animationTable.at(key))
	{
		return _animationTable.at(key);
	}
	else
	{
		auto k = "Animation Data Name " + key + " UNFOUND!";
		log(k.c_str());
	}
}
