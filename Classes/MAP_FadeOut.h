#ifndef __MAP_FADEOUT__
#define __MAP_FADEOUT__

#include "cocos2d.h"
#include "M_ActionParser.h"

using namespace cocos2d;

class MAP_FadeOut :public M_ActionParser
{
private:
	void fadeOut(Node* node,float dt);
public:
	CREATE_ACTIONPARSER(MAP_FadeOut);
	FiniteTimeAction* getAction(Node*,std::vector<std::string>);
	FiniteTimeAction* getAction(Node*,Vector<String*>*);
};

#endif