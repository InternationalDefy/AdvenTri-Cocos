#include "Ref2Effect.h"

using namespace cocos2d;

void ME_Blur::setTarget(M_EffectSprite *sprite)
{
	Size size = sprite->getTexture()->getContentSizeInPixels();
	_glprogramstate->setUniformVec2("resolution", size);
	_glprogramstate->setUniformFloat("blurRadius", _blurRadius);
	_glprogramstate->setUniformFloat("sampleNum", _blurSampleNum);
}

bool ME_Blur::init(float blurRadius, float sampleNum)
{
	initGLProgramState("shadow_blur.fsh");
	_blurRadius = blurRadius;
	_blurSampleNum = sampleNum;
	return true;
}

void ME_Blur::setBlurRadius(float radius)
{
	_blurRadius = radius;
}

void ME_Blur::setBlurSampleNum(float num)
{
	_blurSampleNum = num;
}