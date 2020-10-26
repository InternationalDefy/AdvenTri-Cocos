#ifndef __M_CALLBACK_PARSER__
#define __M_CALLBACK_PARSER__

#define CREATE_CALLBACKPARSER(__TYPE__) \
__TYPE__* __TYPE__::create(SD_Callback* stringData) \
{ \
    __TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
    if (pRet&&pRet->init()) \
			    { \
		pRet->autorelease(); \
		pRet->_stringData=stringData; \
		pRet->initWithStringData(stringData);\
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

class SD_Callback;
class Sys_Event;

using namespace cocos2d;

class M_CallbackParser :public Node
{
private:
	Node* _pNode;
	std::string _eventName;
	int _proximity;
	float _coolDownTime;
	int _limitTimes;
	EventListenerCustom* _listener;
	
	Sys_Event* _system;

	void cooldownEndCallback();

public:

	SD_Callback* _stringData;

	static M_CallbackParser* create(SD_Callback* stringData);

	//virtual init
	virtual void initWithStringData(SD_Callback* stringData);
	virtual void onCustomEvent(EventCustom* eventCustom);
	//limition handle
	void updateLimit();
	//basic actions;
	void initLimit(SD_Callback* stringData);
	void assignListener();
	void removeSelf();
	void initEventName(SD_Callback* stringData);
	//sys manage
	void setSystem(Sys_Event* sys);
	void removeListener();
	//getters && setters
	std::string getEventName();
	void setParentNode(Node* pNode);
	Node* getParentNode();

	Node* getLayer(){ return getParent()->getLayer(); }
	const Node* getLayer() const { return getParent()->getLayer(); }
};

#endif