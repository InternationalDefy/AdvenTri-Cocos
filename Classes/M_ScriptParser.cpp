#include "M_ScriptParser.h"

using namespace cocos2d;

#define MAX_STACK 256 

void M_ScriptParser::push(oStvk data)
{
	if (stack.size() <= MAX_STACK);
	{
		stack.push_back(data); 
		return;
	}
	log("STACK Overflow!");
	return;
}
M_ScriptParser::oStvk M_ScriptParser::pop()
{
	if (stack.size() == 0)
	{
		log("Empty Stack!");
		return oStvk();
	}
	oStvk k = stack.at(stack.size() - 1);
	stack.pop_back();
	return k;
}

bool M_ScriptParser::handleJudgeScript(Vector<String*>* scr)
{
	resetParser();
	scripts = scr;
	_JudgeScriptHandleInstance();
	bool retb = stack.at(stack.size() - 1).i;
	return retb;
}
void M_ScriptParser::resetParser()
{
	numScp = 0;
	stack.clear();
}
bool M_ScriptParser::init()
{
	return TRUE;
}
M_ScriptParser* M_ScriptParser::create()
{
	auto pRet = new (std::nothrow) M_ScriptParser();
	if (pRet&&pRet->init())
	{
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;
}
M_ScriptParser* s_ScriptParser;
M_ScriptParser* M_ScriptParser::getInstance()
{
	if (!s_ScriptParser)
	{
		s_ScriptParser = M_ScriptParser::create();
	}
	return s_ScriptParser;
}