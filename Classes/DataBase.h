#ifndef __DATABASE__
#define __DATABASE__

#include "cocos2d.h"

#define CREATE_DB(__TYPE__) \
__TYPE__* __TYPE__::create() \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet) \
	    { \
		pRet->init(); \
        return pRet; \
	    } \
	    else \
	    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
	    } \
} \
static __TYPE__* s_pRet; \
__TYPE__* __TYPE__::getInstance() \
{ \
	if (!s_pRet) \
	{ \
		s_pRet= __TYPE__::create(); \
	} \
	return s_pRet; \
} \

USING_NS_CC;

class DB: public Ref
{
private:
	int head; int count;
	
public:

	/*
	DB��analyseBegin�����а���������һ����ĩ��ע���е���䣺
	auto k = analyseEndln(stringName);
	k = analyseEndln(stringName);
	*/
	std::string analyseBegin(const std::string& stringName);
	std::string analyseMiddle(const std::string& stringName);
	std::string analyseEndln(const std::string& stringName);

	std::string readFile(std::string fileName);

	virtual void init();
	//HeadLine��DB����ע���е���Ŀ
	virtual int HeadLines()
	{ 
		return 1; 
	}
	/*
	��ȡÿһ�еĲ���
	*/
	virtual void getLine(const std::string& stringName){}
	/*
	usingString����������������д����ʵ�ֲ�ͬ�ַ������ֵ��ļ��ķ���
	*/
	virtual std::string useString()
	{ 
		return 0; 
	}

};

#endif