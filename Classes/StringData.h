#ifndef __STRINGDATA__
#define __STRINGDATA__

#include "cocos2d.h"

using namespace cocos2d;

#define ASSIGN_DATA(__TYPE__,__NAME__) \
private: __TYPE__ _##__NAME__; \
public: __TYPE__ get##__NAME__() {return _##__NAME__;} \
public: void set##__NAME__(__TYPE__ x){_##__NAME__=x;} \

#define ASSIGN_STRING(__NAME__) \
private: std::string _##__NAME__; \
public: std::string get##__NAME__() {return _##__NAME__;} \
public:void set##__NAME__(const std::string& x){_##__NAME__=x;}  \

#define ASSIGN_ITEMS() \
private: Vector<SD_Item*> _lines; \
public: Vector<SD_Item*>* getLines(){ return &_lines; } \

USING_NS_CC;

class SD_Item : public Ref
{
private:
	Vector<String*> _strings;
	virtual bool init()
	{
		return true;
	}
public:
	CREATE_FUNC(SD_Item);
	Vector<String*>* getStrings()
	{
		return &_strings;
	}
	void pushIn(String* x)
	{
		_strings.pushBack(x);
	}
};

class SD: public Ref
{	
private:
	//Vector<SD_Item*> _lines;
	virtual bool init()
	{
		return 0;
	}
public:
	CREATE_FUNC(SD);
	//Vector<SD_Item*>* getLines(){ return &_lines; }
};

#endif