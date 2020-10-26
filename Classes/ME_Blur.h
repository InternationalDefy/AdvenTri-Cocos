#ifndef __M_EFFECT_BLUR__
#define __M_EFFECT_BLUR__

#include "cocos2d.h"

using namespace cocos2d;

class M_Effect;
class M_EffectSprite;

class ME_Blur : public M_Effect
{
public:
	CREATE_FUNC(ME_Blur);
	virtual void setTarget(M_EffectSprite *sprite) override;
	void setBlurRadius(float radius);
	void setBlurSampleNum(float num);

protected:
	bool init(float blurRadius = 5.0f, float sampleNum = 5.0f);

	float _blurRadius;
	float _blurSampleNum;
};


#endif