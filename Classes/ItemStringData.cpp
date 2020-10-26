/*
#include "LaEmojiData.h"

USING_NS_CC;

LaEmojiData* LaEmojiData::create()
{
	LaEmojiData* languageData = new (std::nothrow) LaEmojiData();
	if (languageData)
	{
		languageData->init();
		languageData->autorelease();
		return languageData;
	}
	CC_SAFE_DELETE(languageData);
	return nullptr;
}

std::string LaEmojiData::ReadFileToString(std::string fileName)
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

void LaEmojiData::HandleEmojiDataType(int type, std::string data)
{
	switch (type)
	{
	case 1:
		tempName = data;
		break;
	case 2:
		_emojisSpriteData.insert(tempName, Emoji::create(data));
		break;
	default:
		break;
	}
}

void LaEmojiData::ParseEmoji(std::string stringName)
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

void LaEmojiData::HandleDialogDataType(int type, std::string data)
{
	switch (type)
	{
	case 1:
		tempName = data;
		break;
	case 2:
		_dialogsSpriteData.insert(tempName, Dialog::create(data));
		break;
	default:
		break;
	}
}

void LaEmojiData::ParseDialog(std::string stringName)
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

void LaEmojiData::HandleLanguageReferenceType(int type, std::string data)
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

void LaEmojiData::ParseLanguageReference(std::string stringName)
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

void LaEmojiData::HandleLanguageDataType(LaEmojiList* laEmojiList, int type, std::string data)
{
	//auto str = String::create(data);
	Emoji* emoji = Emoji::create();
	if (type == 1) emoji = Emoji::clone(_emojisSpriteData.at(data));
	switch (type)
	{
	case 1:
		laEmojiList->getEmojis()->pushBack(emoji);
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

void LaEmojiData::PaeseLanguageDataByReference(std::string stringName)
{
	int length = stringName.size();
	int head = 0;
	int count = 0;
	int type = 0;

	numberCount = 0;

	LaEmojiList* laEmojiList = LaEmojiList::create();

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
	Dialog* dialog = Dialog::clone(_dialogsSpriteData.at(stringName.substr(head, count)));
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

void LaEmojiData::init()
{
	//std::string stringOnGo= ReadFileToString("EmojiList.csv");
	ParseEmoji(ReadFileToString("EmojiList.csv"));
	ParseDialog(ReadFileToString("DialogList.csv"));
	ParseLanguageReference(ReadFileToString("LaEmojiReference.csv"));
	for (auto i : _languageAddressData)
	{
		PaeseLanguageDataByReference(ReadFileToString(i->getCString()));
	}
	//log("haha");
}

*/