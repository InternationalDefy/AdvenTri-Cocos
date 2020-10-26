#ifndef __M_STEPHANDLER__
#define __M_STEPHANDLER__

#include "cocos2d.h"

using namespace cocos2d;

class M_StepParser;
class Entity;

class M_StepHandler :public Ref
{
private:
	static M_StepHandler* create();
	void init();
	std::map<std::string, M_StepParser*> smpStepParser;
public:
	static M_StepHandler* getInstance();
	/*
	Ctrl����������е��ж����⣬�ж�ʲôʱ�����ʲô�����⣬
	��ָ���´ﵽStepAction��ʱ����ֻ����һ���£�doIt.
	@param Entity* whom ��Ҫ������ʵ�塣
	@param const std::string& what ����Ѱ�Ҷ�Ӧ��Parser��
	@param void* how ��������һ�� !�������κ����ָ��! �Ĳ�������ʾ���ж��Ĳ�����
	*/
	void runStep(Entity* whom, const std::string& what, void* how);
};

#endif