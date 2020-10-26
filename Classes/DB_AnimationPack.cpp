#include "Ref2Animation.h"

USING_NS_CC;

void DB_AnimationPack::getLine(const std::string& data)
{
	tempPack = SD_AnimationPack::create();
	tempName = analyseMiddle(data);
	int k = std::atoi(analyseMiddle(data).c_str());
	for (auto j = 1; j <= k; ++j)
	{
		tempKey = analyseMiddle(data);
		tempAnimateName =analyseMiddle(data);
		tempPack->setKeyName(tempKey, tempAnimateName);
	}
	analyseEndln(data);
	_animationTable.insert(tempName, tempPack);
}

CREATE_DB(DB_AnimationPack);

SD_AnimationPack* DB_AnimationPack::getAnimationPackSD(const std::string& name)
{
	if (name == "")
	{
		return NULL;
	}
	if (!_animationTable.at(name))
	{
		log("SD_AnimationPack! UnFound!");
		return NULL;
	}
	return _animationTable.at(name);
}