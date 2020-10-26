#include "Ref2Controller.h"

USING_NS_CC;
void DB_Ctrl::getLine(const std::string& data)
{
	tempCStringData = SD_Ctrl::create();
	tempName = analyseMiddle(data).c_str();

	tempCStringData->setType(analyseMiddle(data).c_str());
	tempCStringData->setDelta(std::atof(analyseMiddle(data).c_str()));
	analyseEndln(data);

	std::string temp = analyseMiddle(data);
	int line = 0;
	int item = 0;
	tempIStringData = SD_Item::create();
	while (temp!="ensd")
	{
		if (temp == "endln")
		{
			if (!tempIStringData->getStrings()->size())
			{
				log("It's an empty ItemStringData!");
			}
			tempCStringData->getLines()->pushBack(tempIStringData);
			analyseEndln(data);
			tempIStringData = SD_Item::create();
		}
		else tempIStringData->pushIn(String::create(temp));
		temp = analyseMiddle(data);
	}
	analyseEndln(data);
	_table.insert(tempName, tempCStringData);
	
	/*
	if (tempCStringData->getType() == "Simple")
	{
		tempCStringData->setDelta(std::atof(analyseMiddle(data).c_str()));
		tempCStringData->setNumberOfSteps(std::atoi(analyseMiddle(data).c_str()));

		auto k = tempCStringData->getNumberOfSteps();
		for (auto i = 1; i <= k; ++i)
		{
			auto j = std::atoi(analyseMiddle(data).c_str());
			tempIStringData = SD_Item::create();
			for (auto o = 1; o <= j; ++o)
			{
				tempIStringData->getStrings()->
					pushBack(String::create(analyseMiddle(data).c_str()));
			}
			tempCStringData->getLines()->pushBack(tempIStringData);
		}
		analyseEndln(data);
		_table.insert(tempName, tempCStringData);
		return;
	}
	
	int k = std::atoi(analyseMiddle(data).c_str());
	tempCStringData->setNumberOfParams(k);
	
	for (auto i = 0; i < k; ++i)
	{
		tempCStringData->_Params.push_back(analyseMiddle(data));
	}
	analyseEndln(data);
	_table.insert(tempName,tempCStringData);
	*/
	return;
}

SD_Ctrl* DB_Ctrl::getControllerSD(const std::string& name)
{
	if (_table.at(name))
	{
		return (_table.at(name));
	}
	else
	{
		auto k = "Ctrl_Base SD Name " + name + " UNFOUND!";
		log(k.c_str());
	}
}
CREATE_DB(DB_Ctrl);