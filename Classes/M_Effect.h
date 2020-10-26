#ifndef __M_EFFECT__
#define __M_EFFECT__

#include "cocos2d.h"

using namespace cocos2d;

class M_EffectSprite;

class M_Effect :public Ref
{
public:
	GLProgramState* getGLProgramState() const { return _glprogramstate; }
	virtual void setTarget(M_EffectSprite *sprite){}
protected:
	bool initGLProgramState(const std::string &fragmentFilename);
	M_Effect();
	virtual ~M_Effect();
	GLProgramState* _glprogramstate;
};


#endif