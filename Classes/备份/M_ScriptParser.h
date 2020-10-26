#ifndef __M_SCRIPT_PARSER__
#define __M_SCRIPT_PARSER__

#include "cocos2d.h"

#define ELSEF_RETURN(__STR__,__LIT__,__RET__) \
else if (__STR__==__LIT__) \
{ \
	return __RET__; \
} \
	
using namespace cocos2d;

class M_ScriptParser :public Ref
{
public:
	enum ReturnType
	{
		BOOL,
		INT,
		FLOAT,
		STRING,
	};
	ReturnType changeStringToReturnType(const std::string str)
	{
		if (str == "?BOOL")
		{
			return BOOL;
		}
		ELSEF_RETURN(str, "!BOOL", BOOL)
		ELSEF_RETURN(str, "?INT", INT)
		ELSEF_RETURN(str, "!INT", INT)
		ELSEF_RETURN(str, "?FLOAT", FLOAT)
		ELSEF_RETURN(str, "!FLOAT", FLOAT)
		ELSEF_RETURN(str, "?STRING", STRING)
		ELSEF_RETURN(str, "!STRING", STRING)
		else
		{
			log("Un defined Type!");
		}
	}
	enum ScriptType
	{
		START,
		ACTION,
		STACK,
		BACK,
		EST,
		STOP,
	};
	ScriptType getScriptType(const std::string& str);
	enum ScriptAction
	{
		LITERAL,
		GET_PLAYER,
		GET_HEALTH,
		GET_SAVE,
		PLUS,
		SUB,
		MUL,
		DIV,
	};
	M_ScriptParser::ScriptAction M_ScriptParser::changeStringToScriptAction(const std::string& str)
	{
		if (str == "GETSAVE")
		{
			return ScriptAction::GET_SAVE;
		}
		ELSEF_RETURN(str, "GETPLAYER", GET_PLAYER)
		ELSEF_RETURN(str, "GETHEALTH", GET_HEALTH)
		ELSEF_RETURN(str, "+", PLUS)
		ELSEF_RETURN(str, "-", SUB)
		ELSEF_RETURN(str, "/", DIV)
		ELSEF_RETURN(str, "*", MUL)
		else
		{
			log("Serious?");
			return ScriptAction::LITERAL;
		}		
	}
	/*此为字节码模式的范例设计方案
	enum ScriptType
	{
		LITERAL,
		INT_ADD,
		INT_MUL,
		INT_DIV,
		INT_SUB,
		GET_PLAYER,
		GET_HEALTH,
		GET_SAVE,
	};
	ScriptType changeStringToScriptType(const std::string& str)
	{
		if (str == "LITERAL")
		{
			return LITERAL;
		}
		ELSEF_RETURN(str, "INTADD", INT_ADD)
			ELSEF_RETURN(str, "INTSUB", INT_SUB)
			ELSEF_RETURN(str, "INTMUL", INT_MUL)
			ELSEF_RETURN(str, "INTDIV", INT_DIV)
			ELSEF_RETURN(str, "GETPLAYER", GET_PLAYER)
			ELSEF_RETURN(str, "GETHEALTH", GET_HEALTH)
			ELSEF_RETURN(str, "GETSAVE", GET_SAVE)
		else
		{
			log("Wrong Script!");
		}
	}
	*/
private:
	bool init();
	std::vector<std::string> stack;
	std::vector<ScriptType> types;
	Vector<String*>* scripts;
	std::string pop();
	bool started;
	int top;
	void push(const std::string&);
	void handleLine(int*);
	void handleStartAll();
	void handleBack(int*, const std::string&);
	void handleEst(int*);
	void handleEnd(int*);
	std::string getBack();
	std::string getActionScript();
	ReturnType returnType;
	/*
	std::string retString;
	int retInt;
	float retFloat;
	*/
	void resetParser();
public:
	std::string handleScript(Vector<String*>*);
	
	static M_ScriptParser* getInstance();
	static M_ScriptParser* create();

	void setReturnType(const std::string& str)
	{
		returnType = changeStringToReturnType(str);
	}
	
};

#endif