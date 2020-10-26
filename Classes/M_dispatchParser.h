#ifndef __M_DISPATCH_PARSER__
#define __M_DISPATCH_PARSER__

#define CREATE_DISPATCHPARSER(__TYPE__) \
__TYPE__* __TYPE__::create(SD_Dispatcher* stringData) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet&&pRet->init()) \
		    { \
		pRet->autorelease(); \
		pRet->initWithStringData(stringData); \
		pRet->initLimit(stringData); \
        return pRet; \
		    } \
			    else \
			    { \
        delete pRet; \
        pRet = NULL; \
        return NULL; \
			    } \
} \

#include "cocos2d.h"

class SD_Dispatcher;
class Sys_Event;

using namespace cocos2d;

class M_DispatchParser :public Node
{
private:
	Node* _pNode;
	std::string _eventName;

	int _limitTimes;
	float _coolDownTime;

	bool _locked;

	Sys_Event* _system;

	void cooldownEndCallback();

public:

	static M_DispatchParser* create(SD_Dispatcher* stringData);

	virtual void initWithStringData(SD_Dispatcher* stringData);
	virtual void update(float dt);
	//limition handle
	void updateLimit();
	//basic functions
	void initLimit(SD_Dispatcher* stringData);
	void removeSelf();
	void initEventName(SD_Dispatcher* stringData);
	//setters & getters
	bool isLocked()
	{
		return _locked;
	}
	void setSystem(Sys_Event* sys);
	std::string getEventName();
	virtual void setParentNode(Node* pNode);
	Node* getParentNode();
};

#endif