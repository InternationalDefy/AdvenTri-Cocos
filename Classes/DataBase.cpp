#include "Ref2DataBase.h"

USING_NS_CC;

std::string DB::readFile(std::string fileName)
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
/*
DB的analyseBegin方法中包含跳过第一行行末和注释行的语句：
auto k = analyseEndln(stringName);
k = analyseEndln(stringName);
*/
std::string DB::analyseBegin(const std::string& stringName)
{
	head = 0; count = 0;
	while (stringName[count] != ','&&stringName[count]!='\n') count++;
	std::string s_temp = stringName.substr(head, count);
	head = count + 1;
	if (stringName[count] == '\n')
	{
		count = 0;
	}
	else
	{
		count = 0;
		analyseEndln(stringName);
	}
	for (auto i = 0; i < HeadLines(); ++i)
	{
		analyseEndln(stringName);
	}
	return s_temp;
}
std::string DB::analyseMiddle(const std::string& stringName)
{
	while (stringName[head + count] != ',') count++;
	std::string s_temp = stringName.substr(head, count);
	head += count + 1;
	count = 0;
	return s_temp;
}
std::string DB::analyseEndln(const std::string& stringName)
{
	while (stringName[head + count] != '\n') count++;
	std::string s_temp = stringName.substr(head, count);
	head += count + 1;
	count = 0;
	return s_temp;
}

void DB::init()
{
	std::string data = readFile(useString());
	int n = std::atoi(analyseBegin(data).c_str());
	
	for (int i = 0; i < n; ++i)
	{
		getLine(data);
	}
}
