#include "Ref2LaEmoji.h"

USING_NS_CC;
/*
DB_LaEmoji* DB_LaEmoji::create()
{
	DB_LaEmoji* languageData = new (std::nothrow) DB_LaEmoji();
	if (languageData)
	{
		languageData->init();
		return languageData;
	}
	CC_SAFE_DELETE(languageData);
	return nullptr;
}

std::string DB_LaEmoji::ReadFileToString(std::string fileName)
{
	FILE* pFile;
	fopen_s(&pFile, fileName.c_str(), "r");

	std::string s;

	fseek(pFile, 0, SEEK_END);
	long len = ftell(pFile);
	char* pBuffer = new char[len + 1];
	fseek(pFile, 0, SEEK_SET);
	fread(pBuffer, 1, len, pFile);
	fclose(pFile);

	pBuffer[len] = 0;
	s.assign(pBuffer, len);

	delete[] pBuffer;
	
	return s;
}

void DB_LaEmoji::HandleEmojiDataType(int type, std::string data)
{
	switch (type)
	{
	case 1:
		tempName = data;
		break;
	case 2:
		emojiTemp = SD_Emoji::create();
		emojiTemp->setSpriteTexture(data);
		_emojiTable.insert(tempName, emojiTemp);
		break;
	default:
		break;
	}
}

void DB_LaEmoji::ParseEmoji(std::string stringName)
{
	int length = stringName.size();
	int head = 0;
	int count = 0;
	int type = 0;

	numberCount = 0;

	while (stringName[count] != ',') count++;
	n = std::atoi(stringName.substr(head, count).c_str());
	head = count + 1;
	count = 0;

	while (stringName[head + count] != '\n') count++;
	m = std::atoi(stringName.substr(head, count).c_str());
	head += count + 1;
	count = 0;

	for (int tail = head; tail <= length; ++tail)
	{
		if (stringName[tail] != '\n')
			if (stringName[tail] != ',')
			{
				count++;
			}
			else
			{
				type += 1;
				if (type > m)
					type = 1;
				HandleEmojiDataType(type, stringName.substr(head, count).c_str());
				head = tail + 1;
				count = 0;
			}
		else
		{
			head += 1;
			++numberCount;
		}
	}

}

void DB_LaEmoji::HandleDialogDataType(int type, std::string data)
{
	switch (type)
	{
	case 1:
		tempName = data;
		break;
	case 2:
		dialogTemp = SD_Dialog::create();
		dialogTemp->setFileName(data);
		_dialogTable.insert(tempName, dialogTemp);
		break;
	default:
		break;
	}
}

void DB_LaEmoji::ParseDialog(std::string stringName)
{
	int length = stringName.size();
	int head = 0;
	int count = 0;
	int type = 0;

	numberCount = 0;

	while (stringName[count] != ',') count++;
	n = std::atoi(stringName.substr(head, count).c_str());
	head = count + 1;
	count = 0;

	while (stringName[head + count] != '\n') count++;
	m = std::atoi(stringName.substr(head, count).c_str());
	head += count + 1;
	count = 0;

	for (int tail = head; tail <= length; ++tail)
	{
		if (stringName[tail] != '\n')
			if (stringName[tail] != ',')
			{
				count++;
			}
			else
			{
				type += 1;
				if (type > m)
					type = 1;
				HandleDialogDataType(type, stringName.substr(head, count).c_str());
				head = tail + 1;
				count = 0;
			}
		else
		{
			head += 1;
			++numberCount;
		}
	}

}

void DB_LaEmoji::HandleLanguageReferenceType(int type, std::string data)
{
	auto str = String::create(data);
	switch (type)
	{
	case 1:
		tempInt = std::atoi(data.c_str());
		break;
	case 2:
		_languageAddressData.pushBack(str);
		break;
	default:
		break;
	}
}

void DB_LaEmoji::ParseLanguageReference(std::string stringName)
{
	int length = stringName.size();
	int head = 0;
	int count = 0;
	int type = 0;

	numberCount = 0;

	while (stringName[count] != ',') count++;
	n = std::atoi(stringName.substr(head, count).c_str());
	head = count + 1;
	count = 0;

	while (stringName[head + count] != '\n') count++;
	m = std::atoi(stringName.substr(head, count).c_str());
	head += count + 1;
	count = 0;

	for (int tail = head; tail <= length; ++tail)
	{
		if (stringName[tail] != '\n')
			if (stringName[tail] != ',')
			{
				count++;
			}
			else
			{
				type += 1;
				if (type > m)
					type = 1;
				HandleLanguageReferenceType(type, stringName.substr(head, count).c_str());
				head = tail + 1;
				count = 0;
			}
		else
		{
			head += 1;
			++numberCount;
		}
	}

}

void DB_LaEmoji::HandleLanguageDataType(SD_LaEmoji* laEmojiList, int type, std::string data)
{
	//auto str = String::create(data);
	emojiTemp = SD_Emoji::create();
	if (type == 1) emojiTemp =_emojiTable.at(data)->clone();
	switch (type)
	{
	case 1:
		laEmojiList->getEmojis()->pushBack(emojiTemp);
		break;
	case 2:
		laEmojiList->getEmojis()->at(numberCount)->setAdjustSize(
			std::atof(data.c_str()));
		break;
	case 3:
		laEmojiList->getEmojis()->at(numberCount)->setDelayTime(
			std::atof(data.c_str()));
		break;
	default:
		break;
	}
}

void DB_LaEmoji::PaeseLanguageDataByReference(std::string stringName)
{
	int length = stringName.size();
	int head = 0;
	int count = 0;
	int type = 0;

	numberCount = 0;

	SD_LaEmoji* laEmojiList = SD_LaEmoji::create();

	while (stringName[count] != ',') count++;
	//n = std::atoi(stringName.substr(head, count).c_str());
	laEmojiList->setAnimation(std::atoi(stringName.substr(head, count).c_str()));
	
	head = count + 1;
	count = 0;

	while (stringName[head + count] != ',') count++;
	laEmojiList->setNumberOfEmojis(std::atoi(stringName.substr(head, count).c_str()));

	head += count +1;
	count = 0;

	while (stringName[head + count] != '\n') count++;
	laEmojiList->setNumberOfItems(std::atoi(stringName.substr(head, count).c_str()));
	m=std::atoi(stringName.substr(head, count).c_str());

	head += count + 1;
	count = 0;

	while (stringName[head + count] != ',') count++;
	SD_Dialog* dialog = _dialogTable.at(stringName.substr(head, count))->clone();
	laEmojiList->setDialog(dialog);

	head += count + 1;
	count = 0;

	while (stringName[head + count] != ',') count++;
	laEmojiList->getDialog()->setAdjustSize(Vec2(std::atoi(stringName.substr(head,count).c_str()),
		laEmojiList->getDialog()->getAdjustSize().y));

	head += count + 1;
	count = 0;

	while (stringName[head + count] != ',') count++;
	laEmojiList->getDialog()->setAdjustSize(	Vec2(laEmojiList->getDialog()->getAdjustSize().x, 
		std::atoi(stringName.substr(head, count).c_str())));

	head += count + 1;
	count = 0;

	while (stringName[head + count] != ',') count++;
	laEmojiList->getDialog()->setBorder(std::atoi(stringName.substr(head, count).c_str()));

	head += count + 1;
	count = 0;

	while (stringName[head + count] != ',') count++;
	laEmojiList->getDialog()->setBlockSpace(std::atoi(stringName.substr(head, count).c_str()));

	head += count + 1;
	count = 0;

	while (stringName[head + count] != '\n') count++;
	laEmojiList->getDialog()->setLineSpace(std::atoi(stringName.substr(head, count).c_str()));

	head += count + 1;
	count = 0;

	for (int tail = head; tail <= length; ++tail)
	{
		if (stringName[tail] != '\n')
			if (stringName[tail] != ',')
			{
				count++;
			}
			else
			{
				type += 1;
				if (type > m)
					type = 1;
				HandleLanguageDataType(laEmojiList, type, stringName.substr(head, count).c_str());
				head = tail + 1;
				count = 0;
			}
		else
		{
			head += 1;
			++numberCount;
		}
	}

	_laEmojiListData.pushBack(laEmojiList);
}

void DB_LaEmoji::init()
{
	//std::string stringOnGo= ReadFileToString("EmojiList.csv");
	ParseEmoji(ReadFileToString("List_Emoji.csv"));
	ParseDialog(ReadFileToString("List_Dialog.csv"));
	ParseLanguageReference(ReadFileToString("Ref_LaEmoji.csv"));
	for (auto i : _languageAddressData)
	{
		PaeseLanguageDataByReference(ReadFileToString(i->getCString()));
	}
	//log("haha");
}
*/

void DB_LaEmoji::getLine(const std::string& data)
{
	tempSD = SD_LaEmoji::create();
	tempName = analyseMiddle(data);
	tempSD->setAnimationName(analyseMiddle(data));
	auto k = std::atoi(analyseEndln(data).c_str());
	tempSD->setNumberOfEmoji(k);
	tempSD->setDialog(SD_Dialog::create(
		DB_Dialog::getInstance()->getDialogSD(analyseMiddle(data))->getFileName()));
	auto x = std::atof(analyseMiddle(data).c_str());
	auto y = std::atof(analyseMiddle(data).c_str());
	tempSD->getDialog()->setAdjustSize(Vec2(x, y));
	tempSD->getDialog()->setBorder(std::atoi(analyseMiddle(data).c_str()));
	tempSD->getDialog()->setBspace(std::atoi(analyseMiddle(data).c_str()));
	tempSD->getDialog()->setLSpace(std::atoi(analyseEndln(data).c_str()));
	for (int i = 0; i < k; ++i)
	{
		auto e = SD_Emoji::create(
			DB_Emoji::getInstance()->getEmojiSD(analyseMiddle(data))->getFileName());
		e->setEnterActionType(analyseMiddle(data));
		e->setAdjustSize(std::atof(analyseMiddle(data).c_str()));
		auto m = std::atoi(analyseMiddle(data).c_str());
		auto str = analyseMiddle(data);
		e->pushEnterActionParam(str);
		e->setTimeDelay(std::atof(str.c_str()));
		if (m != 1)
		{
			for (auto j = 0; j < m; ++j)
			{
				e->pushEnterActionParam(analyseMiddle(data));
			}
		}
		analyseEndln(data);
		tempSD->pushSdEmoji(e);
	}
	_table.insert(tempName, tempSD);
	return;
}

SD_LaEmoji* DB_LaEmoji::getLaEmojiSD(const std::string& name)
{
	if (_table.at(name))
	{
		return _table.at(name);
	}
	else
	{
		auto k = "LaEmoji StringData Name: " + name + " UNFOUND!";
		log(k.c_str());
	}
}

CREATE_DB(DB_LaEmoji);