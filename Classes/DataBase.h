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
	DB的analyseBegin方法中包含跳过第一行行末和注释行的语句：
	auto k = analyseEndln(stringName);
	k = analyseEndln(stringName);
	*/
	std::string analyseBegin(const std::string& stringName);
	std::string analyseMiddle(const std::string& stringName);
	std::string analyseEndln(const std::string& stringName);

	std::string readFile(std::string fileName);

	virtual void init();
	//HeadLine是DB跳过注释行的数目
	virtual int HeadLines()
	{ 
		return 1; 
	}
	/*
	读取每一行的操作
	*/
	virtual void getLine(const std::string& stringName){}
	/*
	usingString函数在派生类中重写可以实现不同字符串名字的文件的访问
	*/
	virtual std::string useString()
	{ 
		return 0; 
	}

};

#endif