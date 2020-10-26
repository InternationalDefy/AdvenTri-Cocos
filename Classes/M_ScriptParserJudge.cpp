#include "M_ScriptParser.h"

using namespace cocos2d;

void M_ScriptParser::_JudgeScriptHandleInstance()
{
	while (numScp < scripts->size())
	{
		auto type = changeStringToScriptType(scripts->at(numScp)->getCString());
		switch (type)
		{
		case L_INT:
			_ScriptHandlerLITERALInt();
			break;
		case L_FLOAT:
			_ScriptHandlerLITERALFloat();
			break;
		case L_STRING:
			_ScriptHandlerLITERALString();
			break;
		case J_UP:
			_ScriptHandlerJUDGEUp();
			break;
		case FUNC_GETSAVE:
			_ScriptHandlerFUNCATIONGetsave();
			break;
		case RET_BOOL:
			_ScriptHandlerRETURNBool();
			break;
		default:
			log("Script UnDefined!");
			break;
		}
		numScp += 1;
	}
}
void M_ScriptParser::_ScriptHandlerLITERALInt()
{
	oStvk stvk;
	numScp++;
	stvk.i = std::atoi(scripts->at(numScp)->getCString());
	push(stvk);
}
void M_ScriptParser::_ScriptHandlerLITERALFloat()
{
	oStvk stvk;
	numScp++;
	stvk.f = std::atof(scripts->at(numScp)->getCString());
	push(stvk);
}
void M_ScriptParser::_ScriptHandlerLITERALString()
{
	oStvk stvk;
	numScp++;
	stvk.str = scripts->at(numScp)->getCString();
	push(stvk);
}
void M_ScriptParser::_ScriptHandlerFUNCATIONGetsave()
{
	//do something aboot save system
}
void M_ScriptParser::_ScriptHandlerJUDGEUp()
{
	oStvk os2 = pop();
	oStvk os1 = pop();
	oStvk res;
	if (os1.i > os2.i)
	{
		res.i = 1;
	}
	else if (os1.f > os2.f)
	{
		res.i = 1;
	}
	else res.i = 0;
	push(res);
}
void M_ScriptParser::_ScriptHandlerRETURNBool()
{
	numScp = scripts->size();
}
