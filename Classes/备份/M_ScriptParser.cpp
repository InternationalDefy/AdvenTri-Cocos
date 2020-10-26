#include "M_ScriptParser.h"

using namespace cocos2d;

#define MAX_STACK 128 

void M_ScriptParser::push(const std::string& data)
{
	if (stack.size <= MAX_STACK);
	{
		stack.push_back(data); 
		top += 1;
		return;
	}
	log("STACK Overflow!");
	return;
}
std::string M_ScriptParser::pop()
{
	if (stack.size == 0)
	{
		log("Empty Stack!");
		return "";
	}
	std::string k = stack.at(stack.size - 1);
	stack.pop_back();
	types.pop_back();
	top -= 1;
	return k;
}
M_ScriptParser::ScriptType M_ScriptParser::getScriptType(const std::string& str)
{
	if (!started)
	{
		return START;
	}
	if (stack.empty())
	{
		return ACTION;
	}
	if (str == "est")
	{
		return EST;
	}
	if (str.at(0) == '.')
	{
		return STOP;
	}
	if (str == "<" || str == ">" || str == "!")
	{
		return BACK;
	}
	return STACK;
}
//handle被设为0时意味着脚本结束。
//scripts是脚本的容器
//stack是当前数据的栈
//push pop的操作对象是 stack
//push操作要考虑输入值的类型push，pop操作集合了类型的pop
//type是当前栈重各类脚本的类型
void M_ScriptParser::handleLine(int* handle)
{
	auto sct = scripts->at(*handle)->getCString();
	*handle += 1;
	auto type = getScriptType(sct);
	switch (type)
	{
	case M_ScriptParser::START:
		started = TRUE;
		push(sct);
		types.push_back(type);
		setReturnType(sct);
		break;
	case M_ScriptParser::ACTION:
		push(sct);
		types.push_back(type);
		break;
	case M_ScriptParser::STACK:
		push(sct);
		types.push_back(type);
		break;
	case M_ScriptParser::BACK:
		handleBack(handle,sct);
		break;
	case M_ScriptParser::EST:
		handleEnd(handle);
		break;
	case M_ScriptParser::STOP:
		push(sct);
		types.push_back(type);
		break;
	default:
		break;
	}
	/*
	ScriptType spt = changeStringToScriptType(sct);
	std::string temp;
	switch (spt)
	{
	case M_ScriptParser::LITERAL:
		push(scripts->at(*handle)->getCString());
		*handle += 1;
		break;
	case M_ScriptParser::INT_ADD:
		auto k1 = std::atoi(pop().c_str());
		auto k2 = std::atoi(pop().c_str());
		temp = std::to_string(k1 + k2);
		push(temp);
		break;
	case M_ScriptParser::INT_MUL:
		auto k1 = std::atoi(pop().c_str());
		auto k2 = std::atoi(pop().c_str());
		temp = std::to_string(k1 * k2);
		push(temp);
		break;
	case M_ScriptParser::INT_DIV:
		auto k1 = std::atoi(pop().c_str());
		auto k2 = std::atoi(pop().c_str());
		temp = std::to_string(k2 / k1);
		push(temp);
		break;
	case M_ScriptParser::INT_SUB:
		auto k1 = std::atoi(pop().c_str());
		auto k2 = std::atoi(pop().c_str());
		temp = std::to_string(k2 - k1);
		push(temp);
		break;
	case M_ScriptParser::GET_PLAYER:
		break;
	case M_ScriptParser::GET_HEALTH:
		break;
	case M_ScriptParser::GET_SAVE:
		break;
	default:
		break;
	}
	*/
}
void M_ScriptParser::handleEnd(int* handle)
{
	*handle = 0;
	auto k = getActionScript();
	push(k);
}
void M_ScriptParser::handleBack(int* handle,const std::string& str)
{
	bool useIt = FALSE;
	auto right = getBack();
	auto left = getBack();
	if (str == "<")
	{
		useIt = std::atof(left.c_str()) < std::atof(right.c_str());
	}
	else if (str == ">")
	{
		useIt = std::atof(left.c_str()) > std::atof(right.c_str());
	}
	else if (str == "!")
	{
		useIt = std::atoi(left.c_str()) != std::atoi(right.c_str());
	}
	if (useIt)
	{
		*handle = 0;
		auto k = getActionScript();
		push(k);
	}
	else 
	{
		stack.clear();
		types.clear();
		top = 0;
	}
}
std::string M_ScriptParser::getActionScript()
{
	while (types.at(top - 1) != ACTION)
	{
		pop();
	}
	auto ret = pop();
	return ret;
}
std::string M_ScriptParser::getBack()
{
	if (types.at(top - 1) != STOP)
	{
		log("Wrong When Parsing!");
	}
	int div;
	int dived;
	const char* geta(NULL);
	const char* type(NULL);

	std::string sct = pop();
	ScriptAction stp = changeStringToScriptAction(sct);
	switch (stp)
	{
	case M_ScriptParser::LITERAL:
		break;
	case M_ScriptParser::GET_PLAYER:
		break;
	case M_ScriptParser::GET_HEALTH:
		break;
	case M_ScriptParser::GET_SAVE:
		type = pop().c_str();
		geta = pop().c_str();
		//push(Sys_Save::getInstance()->getString(geta,type));
		break;
	case M_ScriptParser::DIV:
		div = std::atoi(pop().c_str());
		dived = std::atoi(pop().c_str());
		push(std::to_string(dived / div));
		types.push_back(ScriptType::STACK);
		break;
	case M_ScriptParser::MUL:
		div = std::atoi(pop().c_str());
		dived = std::atoi(pop().c_str());
		push(std::to_string(dived * div));
		types.push_back(ScriptType::STACK);
		break;
	case M_ScriptParser::PLUS:
		div = std::atoi(pop().c_str());
		dived = std::atoi(pop().c_str());
		push(std::to_string(dived + div));
		types.push_back(ScriptType::STACK);
		break;
	case M_ScriptParser::SUB:
		div = std::atoi(pop().c_str());
		dived = std::atoi(pop().c_str());
		push(std::to_string(dived - div));
		types.push_back(ScriptType::STACK);
		break;
	default:
		break;
	}
	
}
std::string M_ScriptParser::handleScript(Vector<String*>* scr)
{
	resetParser();
	
	scripts = scr;
	
	int k = 0;
	handleLine(&k);
	
	while (k)
	{
		handleLine(&k);
	}
	return stack.at(0);
}
void M_ScriptParser::resetParser()
{
	stack.clear();
	types.clear();
	top = 0;
	scripts->clear();
	/*
	retInt = 0;
	retFloat = 0.0f;
	retString = "";
	*/
	started = FALSE;
}
bool M_ScriptParser::init()
{
	started = FALSE;
	top = 0;
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