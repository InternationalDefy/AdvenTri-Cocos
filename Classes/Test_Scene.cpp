#include "Ref2TestCase.h"
#include "Ref2SceneSystem.h"

Test_Scene::Test_Scene()
{
	testLayer = NULL;
}
Test_Scene* s_TestScene;
Test_Scene* Test_Scene::getInstance()
{
	if (!s_TestScene)
	{
		s_TestScene = Test_Scene::create();
	}
	return s_TestScene;
}
Test_Scene* Test_Scene::create()
{
	auto pRet = new Test_Scene();
	if (pRet)
	{
		pRet->retain();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
}

Scene* Test_Scene::testSceneGameLayer(const std::string& name, bool testDataBase)
{
	if (testDataBase)
	{
		this->testDataBase();
	}
	testLayer = Test_Layer::getInstance();
	Scene* sc = Test_Layer::getInstance()->getTestBoxStart(name);
	return sc;
}

void Test_Scene::testDataBase()
{
	//Ӧ���У����ǿ����ޣ�Ŀǰ�Ȳ�����DB�ļ��в���
	//2018-10-13 ��
}
