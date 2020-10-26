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
private:
	/*
	脚本类型以及判断使用的返回参数。
	前缀表示的是其具体的类型。
	Literal 字面值
	Funcation 函数回调
	Judge 判断
	Return 返回
	*/
	enum ScriptType
	{
		NONE,
		L_INT,
		L_FLOAT,
		L_STRING,
		FUNC_GETSAVE,
		J_UP,
		RET_BOOL,
	};
	ScriptType changeStringToScriptType(const std::string& data)
	{
		if (data == "INT")
		{
			return M_ScriptParser::ScriptType::L_INT;
		}
		ELSEF_RETURN(data, "FLOAT", ScriptType::L_FLOAT)
		ELSEF_RETURN(data, "STRING", ScriptType::L_STRING)
		ELSEF_RETURN(data, "GETSAVE", ScriptType::FUNC_GETSAVE)
		ELSEF_RETURN(data, ">", ScriptType::J_UP)
		ELSEF_RETURN(data, "RET_BOOL", ScriptType::RET_BOOL)
		else
		{
			log("Undefined Type!");
			return ScriptType::NONE;
		}
	}
private:
	//作为栈操作的数据单元使用 包含三种数据类型。
	struct oStvk
	{
		int i;
		float f;
		std::string str;   
		oStvk()  //默认构造函数  
		{
			i = 0;
			f = 0.0f;
			str = "";
		}
	};
private:
	void _ScriptHandlerLITERALInt();
	void _ScriptHandlerLITERALFloat();
	void _ScriptHandlerLITERALString();
	void _ScriptHandlerFUNCATIONGetsave();
	void _ScriptHandlerJUDGEUp();
	void _ScriptHandlerRETURNBool();
private:
	//基础属性和创建以及初始化操作。
	static M_ScriptParser* create();
	bool init();
	std::vector<oStvk> stack;
	Vector<String*>* scripts;	
	bool started;
	void resetParser();
	//基础的栈操作。
	void push(oStvk);
	int numScp;
	oStvk pop();
	//直接开始handleScript。
	void _JudgeScriptHandleInstance();
public:
	/*
	此操作是判断型脚本的外部执行操作
	传入一个以?开启的解析脚本序列，返回值是bool型
	得到的bool值用于设置。使用方法举例：
	在SD_Scene
	?脚本序列 XXX元素
	*在SD受到生成操作的调用之后，先执行脚本，若得到的为FALSE，则不生成该元素。
	**但需要在SD中，将元素序列分开为二，即需要脚本的和不需要脚本的。
	***或者统一设置为需要脚本，一定使用的元素在其前方加入 "? INT 1 RET"
	*/
	bool handleJudgeScript(Vector<String*>*);
	
	static M_ScriptParser* getInstance();

};

#endif