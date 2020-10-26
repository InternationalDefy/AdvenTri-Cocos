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
	�ű������Լ��ж�ʹ�õķ��ز�����
	ǰ׺��ʾ�������������͡�
	Literal ����ֵ
	Funcation �����ص�
	Judge �ж�
	Return ����
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
	//��Ϊջ���������ݵ�Ԫʹ�� ���������������͡�
	struct oStvk
	{
		int i;
		float f;
		std::string str;   
		oStvk()  //Ĭ�Ϲ��캯��  
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
	//�������Ժʹ����Լ���ʼ��������
	static M_ScriptParser* create();
	bool init();
	std::vector<oStvk> stack;
	Vector<String*>* scripts;	
	bool started;
	void resetParser();
	//������ջ������
	void push(oStvk);
	int numScp;
	oStvk pop();
	//ֱ�ӿ�ʼhandleScript��
	void _JudgeScriptHandleInstance();
public:
	/*
	�˲������ж��ͽű����ⲿִ�в���
	����һ����?�����Ľ����ű����У�����ֵ��bool��
	�õ���boolֵ�������á�ʹ�÷���������
	��SD_Scene
	?�ű����� XXXԪ��
	*��SD�ܵ����ɲ����ĵ���֮����ִ�нű������õ���ΪFALSE�������ɸ�Ԫ�ء�
	**����Ҫ��SD�У���Ԫ�����зֿ�Ϊ��������Ҫ�ű��ĺͲ���Ҫ�ű��ġ�
	***����ͳһ����Ϊ��Ҫ�ű���һ��ʹ�õ�Ԫ������ǰ������ "? INT 1 RET"
	*/
	bool handleJudgeScript(Vector<String*>*);
	
	static M_ScriptParser* getInstance();

};

#endif