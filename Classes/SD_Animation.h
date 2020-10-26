#ifndef __SD_ANIMATION__
#define __SD_ANIMATION__

#include "Ref_DataBase.h"

using namespace cocos2d;

class SD_Animation :public SD
{
private:
	ASSIGN_DATA(int, NumberOfParams);
	ASSIGN_STRING(AnimationTypeName);
	std::vector<std::string> _Params;
private:
	bool init();
public:
	static SD_Animation* create();
	std::vector<std::string>* getParamPointer()
	{
		return &_Params;
	}
	void pushParam(const std::string& str)
	{
		_Params.push_back(str);
	}
};

#endif